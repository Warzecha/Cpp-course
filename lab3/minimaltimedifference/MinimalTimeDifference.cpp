//
// Created by damian on 13.03.18.
//

#include <iostream>
#include "MinimalTimeDifference.h"

namespace minimaltimedifference
{
    unsigned int ToMinutes(std::string time_HH_MM) {

        std::regex time_expression("([0-9]+):([0-9]+)");
        std::cmatch m;

        const char *time = time_HH_MM.c_str();
        std::regex_match(time, m, time_expression);

        int hour = std::stoi(m[1].str());
        int minute = std::stoi(m[2].str());

        return static_cast<unsigned int>(hour * 60 + minute);

    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {


        std::vector<unsigned int> time_in_minutes;
        for( auto t : times)
        {
            time_in_minutes.push_back(ToMinutes(t));

        }

        std::sort(time_in_minutes.begin(),time_in_minutes.end());

        unsigned int difference = static_cast<unsigned int>((1440 - *(time_in_minutes.end()-1) + *time_in_minutes.begin() ));

        //std::cout<<"diff = "<<*time_in_minutes.begin()<<std::endl;

        for(auto it = time_in_minutes.begin(); it != time_in_minutes.end() - 1; it++)
        {

            if( *(it+1) - *it < difference)
            {
                //std::cout<<"not ok";
                difference = *(it+1) - *it;
            }

        }


        return difference;
    }

}


