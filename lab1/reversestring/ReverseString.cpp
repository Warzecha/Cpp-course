//
// Created by damian on 27.02.18.
//

#include "ReverseString.h"


std::string reverse(std::string str)
{

    if(str[0] != '\0')
    {
        std::string new_str;

        return str.substr(0,str.length()-1) + str[0];

    }
    else return "";



}