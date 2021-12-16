cmake_minimum_required(VERSION 3.20)
project(AdvacedProgramming)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvacedProgramming main.cpp anomaly_detection_util.cpp anomaly_detection_util.h
        timeseries.cpp timeseries.h AnomalyDetector.h SimpleAnomalyDetector.cpp SimpleAnomalyDetector.h
        minCircle.cpp minCircle.h HybridAnomalyDetector.cpp HybridAnomalyDetector.h DefaultIO.h Command.h)
