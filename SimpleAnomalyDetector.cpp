//
// Created by omri on 06/11/2021.


#include <math.h>
#include "SimpleAnomalyDetector.h"


//-------------------------------------------------------------------------------
/**
 *
 * @param v1 vector
 * @param v2 vector
 * @param l linear regression line
 * @return the threshold times 1.1
 */
float CalculateThreshold(vector<float> v1, vector<float> v2,Line l) {
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
        Line l = linear_reg(pointArray,v1.size());
        for (int i = 0; i < v1.size();i++) {
            delete pointArray[i];
        }
        return l;
}
//-------------------------------------------------------------------------------
/**
 * default constructor
 */
SimpleAnomalyDetector::SimpleAnomalyDetector() {
    // TODO Auto-generated constructor stub

}
/**
 * default destructor
 */
SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

/**
 * learns the normal data from a provided CSV file
 * @param ts
 */
void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
    map<string, vector<float>>::iterator itTable1;
    map<string, vector<float>>::iterator itTable2;
    map<string, vector<float>> table = ts.getTable();
    vector<float>::iterator iterSize;
    map<string, vector<float>>::iterator t;
    t = table.begin();
    int size = 0;
    for(iterSize = t->second.begin(); iterSize != t->second.end();iterSize++){
        //size of vector
        size += 1;
    }
    for (itTable1 = table.begin(); itTable1 != table.end().operator--(); itTable1++) {
        //iterates over the table
        string col = "";
        float maxPearsonReturn = 0;
        float pearsonReturn = 0;
        float *vector1 = itTable1->second.data();
        for (itTable2 = next(itTable1); itTable2 != table.end(); ++itTable2) {
            //iterates over the vectors from the current one to the end
            float *vector2 = itTable2->second.data();
            pearsonReturn = abs(pearson(vector1, vector2, size));
            if (pearsonReturn > maxPearsonReturn) {
                //calculates the max pearson
                col = itTable2->first;
                maxPearsonReturn = pearsonReturn;
            }
        }
        if ((col != "")&&(maxPearsonReturn >= 0.9)) {
            //creates a new correlatedFeatures struct that represents two correlated vectors
            struct correlatedFeatures cor;
            cor.feature1 = itTable1->first;
            cor.feature2 = col;
            cor.corrlation = maxPearsonReturn;
            cor.lin_reg = makeLinearRegression(itTable1->second, table.find(col)->second);
            cor.threshold = CalculateThreshold(itTable1->second, table.find(col)->second, cor.lin_reg);
            cf.push_back(cor);
        }
    }
}
/**
 * checks if the dev is higher than the threshold. if it is, creates a new AnomalyReport object.
 * @param l linear regression line
 * @param p point
 * @param threshold to compare to
 * @param index of row
 * @param s the names of the two vectors
 */
void SimpleAnomalyDetector::checkDev(Line l, Point p, float threshold, long index, string s) {
    float devReturn = dev(p,l);
    if ( devReturn > threshold) {
        AnomalyReport a(s, index + 1);
        anomalyReports.push_back(a);
    }
}
/**
 * detects anomalies in the data
 * @param ts the CSV file data
 * @return a vector of the all the anomaly reports.
 */
vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
    for(long i = 0; i < ts.getTable().begin()->second.size(); i++) {
        //iterates over each row
        vector<correlatedFeatures>::iterator it = this->cf.begin();
        for (;it != this->cf.end(); it++) {
            //iterates over the vector that holds the correlated vectors.
            vector<float> v1 = ts.getTable().find(it->feature1)->second;
            vector<float> v2 = ts.getTable().find(it->feature2)->second;
            string s = it->feature1 + "-" + it->feature2;
            //sends all the data to checkDev that checks if an anomaly was found.
            checkDev(it->lin_reg,Point(v1[i],v2[i]),it->threshold,i,s);
        }
    }
    return anomalyReports;
}
