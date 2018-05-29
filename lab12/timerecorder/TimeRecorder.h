//
// Created by damian on 29.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <utility>
#include <chrono>

namespace profiling
{


    template <typename T>
    template <typename return_type>



    std::pair<return_type, double> TimeRecorder(const T &obj ) {
        return std::pair<return_type, double>();
    }


}


#endif //JIMP_EXERCISES_TIMERECORDER_H
