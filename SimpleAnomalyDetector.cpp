//
// Created by omri on 06/11/2021.
//

#include <math.h>
#include "SimpleAnomalyDetector.h"


//-------------------------------------------------------------------------------


/**
 * make array of pointer to point x is the first vector and y is the second vector.
 * @param v1
 * @param v2
 * @return array of point from the two vectors
 */
Point** makeVecToPointArray(vector<float> v1, vector<float> v2) {
    Point** pointArray = new Point*;
    for(int i=0;i<v1.size();i++)
        pointArray[i] = new Point(v1[i], v2[i]);
    return pointArray;
}

/**
 * make linear regression if the vectors are correlated more then the threshold.
 * @param cf the vector of the struct correlatedFeatures
 * @param ts the time series table
 */
void makeLinearRegression(vector<correlatedFeatures> cf, const TimeSeries &ts) {
    vector<correlatedFeatures>::iterator it;
    map<string, vector<float>> table = ts.getTable();
    for(it = cf.begin();it != cf.end(); it++) {
        vector<float> v1 = table.find(it->feature1)->second;
        vector<float> v2 = table.find(it->feature2)->second;
        if(it->threshold <= it->corrlation) {
            Point** p = makeVecToPointArray(v1, v2);   //make point** for linear_reg
            it->lin_reg = linear_reg(p,v1.size());
        }
    }
}


//-------------------------------------------------------------------------------

SimpleAnomalyDetector::SimpleAnomalyDetector() {
    // TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    // TODO Auto-generated destructor stub
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
    map<string, vector<float>>::iterator itTable1;
    map<string, vector<float>>::iterator itTable2;
    map<string, vector<float>> table = ts.getTable();
    string col = "";
    vector<float>::iterator iterSize;
    map<string, vector<float>>::iterator t;
    t = table.begin();
    int size = 0;
    for(iterSize = t->second.begin(); iterSize != t->second.begin();iterSize++){
        size += 1;
    }
    for (itTable1 = table.begin(); itTable1 != table.end(); itTable1++) {
        float maxPearsonReturn = 0;
        float pearsonReturn = 0;
        float *vector1 = itTable1->second.data();
        for (itTable2 = itTable1++; itTable2 != table.end(); itTable2++) {
            float *vector2 = itTable2->second.data();
            pearsonReturn = abs(pearson(vector1, vector2, size));
            if (pearsonReturn > maxPearsonReturn) {
                col = itTable2->first;
                maxPearsonReturn = pearsonReturn;
            }
        }
        if (col != "") {
            struct correlatedFeatures cor;
            cor.feature1 = itTable1->first;
            cor.feature2 = itTable2->first;
            cor.corrlation = maxPearsonReturn;
            cor.threshold = 0.9;
            cf.push_back(cor);
        }
    }
    makeLinearRegression(cf, ts);
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
    // TODO Auto-generated destructor stub
}
