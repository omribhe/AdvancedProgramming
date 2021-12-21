//
// Uri Greitser 209289891 and Omri Ben Hemo 313255242
//

#include "HybridAnomalyDetector.h"

HybridAnomalyDetector::HybridAnomalyDetector() {
    // TODO Auto-generated constructor stub

}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}
/**
 *
 * @param ts time series object
 * @return vector of anomaly reports, containing their description.
 */
vector<AnomalyReport> HybridAnomalyDetector::detect(const TimeSeries& ts) {
        for (long i = 0; i < ts.getTable().begin()->second.size(); i++) {
            //iterates over each row
            vector<correlatedFeatures>::iterator it = cf.begin();
            for (; it != cf.end(); it++) {
                //uses a detect help function depending on the flag.
                if (it->flag == 1) {
                    detectIfFlagIs1(ts, it, i);
                }
                if (it->flag == 0)
                    detectIfFlagIs0(ts, it, i);
            }
        }
        return anomalyReports;
    }
