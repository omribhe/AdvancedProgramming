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
    SharedInformation shared;
    do {
        dio->write("Welcome to the Anomaly Detection Server.\n");
        dio->write("Please choose an option:\n");
        for(Command* element : menuVector)
            dio->write(element->description);
        std::string s = dio->read();
        const char sFirst = s.front();

        index = sFirst - 49;     // check if input is legal and delete the casting

        menuVector[index]->execute(&shared);
    } while (index != 5);
}


CLI::~CLI() {
}

