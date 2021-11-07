//
// Created by omri on 06/11/2021.
//

#include <math.h>
#include "SimpleAnomalyDetector.h"


//-------------------------------------------------------------------------------
float CalculateTreshold(vector<float> v1, vector<float> v2,Line l) {
    float max = 0;
    for (int i = 0; i<v1.size();i++) {
        Point p(v1[i], v2[i]);
        float temp = dev(p, l);
        if (temp > max)
            max = temp;
    }
    return max*1.1;
    }


/**
 * make linear regression if the vectors are correlated more than the threshold.
 * @param cf the vector of the struct correlatedFeatures
 * @param ts the time series table
 */
Line makeLinearRegression(vector<float> v1, vector<float> v2) {
        Point* pointArray[v1.size()];
        for(int i=0;i<v1.size();i++)
            pointArray[i] = new Point(v1[i], v2[i]);
        return linear_reg(pointArray,v1.size());
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
    vector<float>::iterator iterSize;
    map<string, vector<float>>::iterator t;
    t = table.begin();
    int size = -1;
    for(iterSize = t->second.begin(); iterSize != t->second.end();iterSize++){
        size += 1;
    }
    for (itTable1 = table.begin(); itTable1 != table.end().operator--(); itTable1++) {
        string col = "";
        float maxPearsonReturn = 0;
        float pearsonReturn = 0;
        float *vector1 = itTable1->second.data();
        for (itTable2 = next(itTable1); itTable2 != table.end(); ++itTable2) {
            float *vector2 = itTable2->second.data();
            pearsonReturn = abs(pearson(vector1, vector2, size));
            if (pearsonReturn > maxPearsonReturn) {
                col = itTable2->first;
                maxPearsonReturn = pearsonReturn;
            }
        }
        if ((col != "")&&(maxPearsonReturn >= 0.9)) {
            struct correlatedFeatures cor;
            cor.feature1 = itTable1->first;
            cor.feature2 = col;
            cor.corrlation = maxPearsonReturn;
            cor.lin_reg = makeLinearRegression(itTable1->second, table.find(col)->second);
            cor.threshold = CalculateTreshold(itTable1->second, table.find(col)->second, cor.lin_reg);
            cf.push_back(cor);
        }
    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
    // TODO Auto-generated destructor stub
}
