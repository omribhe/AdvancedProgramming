//
// Uri Greitser 209289891 and Omri Ben Hemo 313255242
//



#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures{
    string feature1,feature2;  // names of the correlated features
    float corrlation;
    Line lin_reg;
    float threshold;
};


class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{
    vector<correlatedFeatures> cf;
    vector<AnomalyReport> anomalyReports;
public:
    SimpleAnomalyDetector();
    virtual ~SimpleAnomalyDetector();

    virtual void learnNormal(const TimeSeries& ts);
    virtual vector<AnomalyReport> detect(const TimeSeries& ts);
    void checkDev(Line l, Point p, float threshold, long index, string s);
    vector<correlatedFeatures> getNormalModel(){
        return cf;
    }

};



#endif /* SIMPLEANOMALYDETECTOR_H_ */