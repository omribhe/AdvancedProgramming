#include "CLI.h"

CLI::CLI(DefaultIO* dio){
    this->dio = dio;
    this->menuVector.push_back(new UploadCSV(dio));
    this->menuVector.push_back(new AlgorithmSettings(dio));
    this->menuVector.push_back(new DetectAnomalies(dio));
    this->menuVector.push_back(new Results(dio));
    this->menuVector.push_back(new UploadAndAnalyze(dio));
    this->menuVector.push_back(new ExitCLI(dio));
}
void printMenu(vector<Command*> menuVector) {
    std::cout << "Welcome to the Anomaly Detection Server."<< std::endl;
    std::cout << "Please choose an option:"<< std::endl;
    for(Command* element : menuVector) {
        cout<< element->description << endl;
    }

}

void CLI::start(){
    int index = 0;
    do {
        printMenu(menuVector);
        cin >> index;
        menuVector[index - 1]->execute();
    } while (index != 6);
}


CLI::~CLI() {
}

