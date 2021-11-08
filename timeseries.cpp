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
/**
 *
 * @param str
 * @return number of data in each row
 */
int TimeSeries::CountNumberOfDataInRow(string str) {
        int n = std::count(str.begin(), str.end(), ',');
        return n + 1;
    }

/**
 *
 * @param CSVfileName
 * @return a map that holds all the data in the CSV
 */
map<string, vector<float>> TimeSeries::fileToMap(const char *CSVfileName)  {
    map<string, vector<float>> mapVector;
    ifstream file;
    file.open(CSVfileName);
    string str;
    int flag = 0;
    int DataNumber = 0;
    //goes over the file line by line
    while (std::getline(file, str)) {
        if (flag == 0) {
            //if its the first line, generates the name and creates a vector for each column
            DataNumber = CountNumberOfDataInRow(str);
            for (int i = 0; i <= DataNumber; i++) {
                //cuts down the string every iteration
                std::string delimiter = ",";
                std::string token = str.substr(0, str.find(delimiter));
                vector<float> col;
                str = str.substr(str.find(delimiter) + 1);
                mapVector.insert({token, col});
            }
            flag = 1;
        } else {
            //if loop isn't in the first line
            map<string, vector<float >>::iterator
                    it = mapVector.begin();
            for (int i = 0; i < DataNumber; i++) {
                //inserts the data into the vectors
                std::string delimiter = ",";
                std::string token = str.substr(0, str.find(delimiter));
                str = str.substr(str.find(delimiter) + 1);
                it->second.push_back(std::stof(token));
                ++it;
                //rests iterator
                if (i == (DataNumber - 1)) {
                    it = mapVector.begin();
                }
            }
        }

    }
    file.close();
    return mapVector;
}