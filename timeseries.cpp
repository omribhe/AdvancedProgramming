//
// Created by omri on 01/11/2021.
//

#include "timeseries.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int TimeSeries::CountNumberOfDataInRow(const char *CSVfileName) {
    ifstream file;
    file.open(CSVfileName);
    string str;
    while (std::getline(file, str)) {
        int n = std::count(str.begin(), str.end(), ',');
        file.close();
        return n + 1;
    }
}

map<string, vector<float>> TimeSeries::fileToMap(const char *CSVfileName)  {
    map<string, vector<float>> mapVector;
    ifstream file;
    file.open(CSVfileName);
    string str;
    int flag = 0;
    int DataNumber = CountNumberOfDataInRow(CSVfileName);
    while (std::getline(file, str)) {
        if (flag == 0) {
            for (int i = 0; i <= DataNumber; i++) {
                std::string delimiter = ",";
                std::string token = str.substr(0, str.find(delimiter));
                vector<float> col;
                str = str.substr(str.find(delimiter) + 1);
                mapVector.insert({token, col});
            }
            flag = 1;
        } else {
            map<string, vector<float >>::iterator
                    it = mapVector.begin();
            for (int i = 0; i < DataNumber; i++) {
                std::string delimiter = ",";
                std::string token = str.substr(0, str.find(delimiter));
                str = str.substr(str.find(delimiter) + 1);
                it->second.push_back(std::stof(token));
                ++it;
                if (i == (DataNumber - 1)) {
                    it = mapVector.begin();
                }
            }
        }

    }
    file.close();
    return mapVector;
}