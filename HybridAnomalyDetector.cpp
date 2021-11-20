//
// Created by omri on 20/11/2021.
//

#include "HybridAnomalyDetector.h"

HybridAnomalyDetector::HybridAnomalyDetector() {
    // TODO Auto-generated constructor stub

}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}
vector<AnomalyReport> HybridAnomalyDetector::detect(const TimeSeries& ts) {
        for (long i = 0; i < ts.getTable().begin()->second.size(); i++) {
            //iterates over each row
            vector<correlatedFeatures>::iterator it = cf.begin();
            for (; it != cf.end(); it++) {
                if (it->flag == 1) {
                    detectIfFlagIs1(ts, it, i);
                }
                if (it->flag == 0)
                    detectIfFlagIs0(ts, it, i);
            }
        }
        return anomalyReports;
    }
