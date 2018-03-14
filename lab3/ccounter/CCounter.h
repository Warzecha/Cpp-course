//
// Created by damian on 14.03.18.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <map>

namespace ccounter
{

    struct Counter
    {

        std::map<std::string, int> values;



    };


    std::unique_ptr<Counter> Init();
    void Inc(std::string key, std::unique_ptr<Counter>* counter);
    int Counts(const std::unique_ptr<Counter> &counter, std::string key);
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);




}


#endif //JIMP_EXERCISES_CCOUNTER_H
