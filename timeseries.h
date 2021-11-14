//
// Uri Greitser 209289891 and Omri Ben Hemo 313255242
//


#ifndef ADVACEDPROGRAMMING_TIMESERIES_H
#define ADVACEDPROGRAMMING_TIMESERIES_H


#include "map"
#include "vector"
using namespace std;

class TimeSeries{
    map<string, vector<float>> Table;
public:
    TimeSeries(const char* CSVfileName){
        this->Table = fileToMap(CSVfileName);
    }
    int CountNumberOfDataInRow(string str);
    map<string, vector<float>> fileToMap(const char *CSVfileName);
    const map<string, vector<float>> getTable() const {
        return Table;
    }

};


#endif //ADVACEDPROGRAMMING_TIMESERIES_H
