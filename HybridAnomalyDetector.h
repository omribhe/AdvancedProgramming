//
// Uri Greitser 209289891 and Omri Ben Hemo 313255242
//



#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector:public SimpleAnomalyDetector {
public:
    HybridAnomalyDetector();
    virtual ~HybridAnomalyDetector();
    virtual vector<AnomalyReport> detect(const TimeSeries& ts);


};

#endif /* HYBRIDANOMALYDETECTOR_H_ */