

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
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

    void createNewCSVFile(std::string name) {
        ofstream out(name);
        string s = read();
        while (s != "done") {
            out<<s<<endl;
            s = read();
        }
        out.close();

    }

	// you may add additional methods here
};

// you may add here helper classes
class SharedInformation{
public:
    float threshold;
    vector<AnomalyReport> reports;
    SharedInformation():threshold(0.9){};
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
    UploadCSV(DefaultIO *dio) : Command(dio, "1. upload a time series csv file") {};
    void execute(SharedInformation* shared) override {
        dio->write("Please upload your local train CSV file.");
        dio->createNewCSVFile("train.csv");
        dio->write("Upload complete.\n");
        dio->write("Please upload your local test CSV file.");
        dio->createNewCSVFile("test.csv");
        dio->write("Upload complete.\n");
    }


};

class AlgorithmSettings : public Command
{
public:
    AlgorithmSettings(DefaultIO *dio) : Command(dio, "2. algorithm settings") {};
    void execute(SharedInformation* shared) override {
        // get the threshold from the shared state
        float temp = 0;
        do {
            dio->write("The current correlation threshold is ");
            dio->write(shared->threshold);
            dio->write("\nType a new threshold\n");
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
    DetectAnomalies(DefaultIO *dio) : Command(dio, "3. detect anomalies") {};
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
    Results(DefaultIO *dio) : Command(dio, "4. display results") {};
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
    UploadAndAnalyze(DefaultIO *dio) : Command(dio, "5. upload anomalies and analyze results") {};
    void execute(SharedInformation* shared) override {
        std::cout<<"upload and analyze on"<<std::endl;
    }


};
class ExitCLI : public Command
{
public:
    ExitCLI(DefaultIO *dio) : Command(dio, "6. exit") {};
    void execute(SharedInformation* shared) override {
        std::cout<<"exit on" <<std::endl;
    }


};








#endif /* COMMANDS_H_ */


