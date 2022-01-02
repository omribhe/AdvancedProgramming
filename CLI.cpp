#include "CLI.h"
#include "stdlib.h"
#include "cstdlib"

CLI::CLI(DefaultIO* dio){
    this->dio = dio;
    this->menuVector.push_back(new UploadCSV(dio));
    this->menuVector.push_back(new AlgorithmSettings(dio));
    this->menuVector.push_back(new DetectAnomalies(dio));
    this->menuVector.push_back(new Results(dio));
    this->menuVector.push_back(new UploadAndAnalyze(dio));
    this->menuVector.push_back(new ExitCLI(dio));
}


void CLI::start(){
    int index = 0;
    do {
        std::cout << "Welcome to the Anomaly Detection Server."<< std::endl;
        std::cout << "Please choose an option:"<< std::endl;
        for(Command* element : menuVector)
            cout<< element->description << endl;
        std::string s = dio->read();
        const char sFirst = s.front();

        index = sFirst - 49;     // check if input is legal and delete the casting
        menuVector[index]->execute();
    } while (index != 6);
}


CLI::~CLI() {
}

