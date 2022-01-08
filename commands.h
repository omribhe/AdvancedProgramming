

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include <sstream>
#include "HybridAnomalyDetector.h"
#include "timeseries.h"

using namespace std;

class DefaultIO{
public:
	virtual string read()=0;
	virtual void write(string text)=0;
	virtual void write(float f)=0;
	virtual void read(float* f)=0;
	virtual ~DefaultIO(){}

    int createNewCSVFile(std::string name) {
        ofstream out(name);
        string s = read();
        int count = -1;
        while (s != "done\n") {
            count++;
            out<<s;
            s = read();
        }
        out.close();
        return count;
    }

	// you may add additional methods here
};

// you may add here helper classes
class UnionReport {
public:
    int start;
    int end;
    string name;
    bool b = false;
};

class SharedInformation{
public:
    float threshold = 0.9;
    vector <AnomalyReport> reports;
    vector <UnionReport> up ;
    int numOfRows = 0;
    int N = 0;
    bool vectorCreated = false;
};


// you may edit this class
class Command{
protected:
	DefaultIO* dio;
public:
    const string description;
	Command(DefaultIO* dio, const string s):dio(dio),description(s){}
	virtual void execute(SharedInformation* shared)=0;
	virtual ~Command(){}
};

// implement here your command classes

class UploadCSV : public Command
{
public:
    UploadCSV(DefaultIO *dio) : Command(dio, "1.upload a time series csv file\n") {};
    void execute(SharedInformation* shared) override {
        dio->write("Please upload your local train CSV file.\n");
        dio->createNewCSVFile("train.csv");
        dio->write("Upload complete.\n");
        dio->write("Please upload your local test CSV file.\n");
        shared->numOfRows = dio->createNewCSVFile("test.csv");
        dio->write("Upload complete.\n");
    }


};

class AlgorithmSettings : public Command
{
public:
    AlgorithmSettings(DefaultIO *dio) : Command(dio, "2.algorithm settings\n") {};
    void execute(SharedInformation* shared) override {
        // get the threshold from the shared state
        float temp = 0;
        do {
            dio->write("The current correlation threshold is ");
            dio->write(shared->threshold);
            dio->write("\n");
            dio->write("Type a new threshold\n");
            dio->read(&temp);
            if (temp < 1 && temp > 0)
                shared->threshold = temp;
            else
                dio->write("please choose a value between 0 and 1.\n");
        }
        while (temp > 1 || temp < 0 );
    }

};
class DetectAnomalies : public Command
{
public:
    DetectAnomalies(DefaultIO *dio) : Command(dio, "3.detect anomalies\n") {};
    void execute(SharedInformation* shared) override{
        HybridAnomalyDetector detector;
        TimeSeries tsTrain("train.csv");
        detector.changeThreshold(shared->threshold);
        detector.learnNormal(tsTrain);
        TimeSeries tsTest("test.csv");
        detector.detect(tsTest);
        shared->reports = detector.getAnomalyReports();
        dio->write("anomaly detection complete.\n");
    };
};

class Results : public Command
{
public:
    Results(DefaultIO *dio) : Command(dio, "4.display results\n") {};
    void execute(SharedInformation* shared) override {
            for(auto it = std::begin(shared->reports); it != std::end(shared->reports); ++it) {
            dio->write(it->timeStep);
            dio->write("\t");
            dio->write(it->description);
            dio->write("\n");
            }
        dio->write("Done.\n");

    }


};
class UploadAndAnalyze : public Command
{
public:
    UploadAndAnalyze(DefaultIO *dio) : Command(dio, "5.upload anomalies and analyze results\n") {};

    void createUnionReportVector(SharedInformation* shared) {
        UnionReport temp;
        UnionReport *tempPtr = &temp;
        bool newBool = true;
        tempPtr->name = std::begin(shared->reports)->description;
        tempPtr->start = std::begin(shared->reports)->timeStep;
        for (auto it = std::begin(shared->reports), last = std::end(shared->reports)-1 ; it != std::end(shared->reports); ++it) {
            if (it->timeStep == last->timeStep) {
                temp.end = it->timeStep;
                shared->up.push_back(*tempPtr);
                break;
            }
            if (it->description == (it + 1)->description) {
                continue;
            } else {
                temp.end = it->timeStep;
                shared->up.push_back(temp);
                temp.start = (it + 1)->timeStep;
                temp.name = (it + 1)->description;
                //UnionReport *tempPtr = &temp;
            }
        }

    }

    void checkAnomalyTimeReport(SharedInformation* shared, int start, int end) {
        for (UnionReport &np: shared->up) {
            if (np.b == true) {
                continue;
            }
            if ((np.start < start) && (np.end < start)) {
                np.b = false;
            } else if ((np.start > end) && (np.end > end)) {
                np.b = false;
            } else {
                np.b = true;
            }
        }
    }


    int checkAnomalyTimes( SharedInformation* shared) {
        int count = 0;
        int N = shared->numOfRows;
        string s = dio->read();
        int start;
        int end;
        while (s != "done\n") {
            vector<string> v;
            stringstream ss(s);
            while(ss.good()) {
                string substr;
                getline(ss, substr, ',');
                stringstream temp(substr);
                getline(temp, substr, '\n');
                v.push_back(substr);
            }
            start = stoi(v.front());
            end = stoi(v.back());
            N -= end-start;
            checkAnomalyTimeReport(shared, start, end);
            count++;
            s = dio->read();
        }
        shared->N = N;
        return count;
    }

    void printAnomalyRate(SharedInformation* shared, int p){
        float count = 0.0;
        float countFalse = 0.0;
        for(UnionReport np: shared->up){
            if(np.b == true){
                count++;
            }
            else
                countFalse++;
        }
        dio->write("True Positive Rate: ");
        float temp = (int)(1000 * count/p)/1000.0;
        dio->write(temp);
        dio->write("\n");
        dio->write("False Positive Rate: ");
        temp = ((int)(1000 * countFalse/shared->N)/1000.0);
        dio->write(temp);
        dio->write("\n");

    }

    void cleanUnionReport(SharedInformation* shared) {
        for (UnionReport &np: shared->up) {
            np.b = false;
        }
    }

    void execute(SharedInformation* shared) override {
        if (shared->vectorCreated == false) {
            createUnionReportVector(shared);
            shared->vectorCreated = true;
        }
        dio->write("Please upload your local anomalies file.\n");
        int P = checkAnomalyTimes(shared);
        dio->write("Upload complete.\n");
        printAnomalyRate(shared, P);
        cleanUnionReport(shared);
    }
};

class ExitCLI : public Command
{
public:
    ExitCLI(DefaultIO *dio) : Command(dio, "6.exit\n") {};
    void execute(SharedInformation* shared) override {
    }
};








#endif /* COMMANDS_H_ */


