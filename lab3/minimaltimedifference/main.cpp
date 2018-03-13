//
// Created by damian on 13.03.18.
//

#include <iostream>
#include "MinimalTimeDifference.h"

int main()
{

    std::vector<std::string> times;
    
    times.push_back("23:59");
    times.push_back("00:01");
    
    std::cout << minimaltimedifference::MinimalTimeDifference(times);


    return 0;
}