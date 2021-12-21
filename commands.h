

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO{
public:
	virtual string read()=0;
	virtual void write(string text)=0;
	virtual void write(float f)=0;
	virtual void read(float* f)=0;
	virtual ~DefaultIO(){}

	// you may add additional methods here
};

// you may add here helper classes


// you may edit this class
class Command{
protected:
	DefaultIO* dio;
public:
    const string description;
	Command(DefaultIO* dio, const string s):dio(dio),description(s){}
	virtual void execute()=0;
	virtual ~Command(){}
};

// implement here your command classes

class UploadCSV : public Command
{
public:
    UploadCSV(DefaultIO *dio) : Command(dio, "1. upload a time series csv file") {};
    void execute() override {
        std::cout<<"Please upload your local train CSV file."<<std::endl;
        string path = dio->read();
        dio->write(path);
    }


};

class AlgorithmSettings : public Command
{
public:
    AlgorithmSettings(DefaultIO *dio) : Command(dio, "2. algorithm settings") {};
    void execute() override {
        std::cout<<"algo settings on"<<std::endl;
    }


};
class DetectAnomalies : public Command
{
public:
    DetectAnomalies(DefaultIO *dio) : Command(dio, "3. detect anomalies") {};
    void execute() override {
        std::cout<<"detect on"<<std::endl;
    }


};

class Results : public Command
{
public:
    Results(DefaultIO *dio) : Command(dio, "4. display results") {};
    void execute() override {
        std::cout<<"results on"<<std::endl;
    }


};
class UploadAndAnalyze : public Command
{
public:
    UploadAndAnalyze(DefaultIO *dio) : Command(dio, "5. upload anomalies and analyze results") {};
    void execute() override {
        std::cout<<"upload and analyze on"<<std::endl;
    }


};
class ExitCLI : public Command
{
public:
    ExitCLI(DefaultIO *dio) : Command(dio, "6. exit") {};
    void execute() override {
        std::cout<<"exit on" <<std::endl;
    }


};








#endif /* COMMANDS_H_ */


