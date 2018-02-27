//
// Created by damian on 27.02.18.
//

#include "ReverseString.h"


std::string reverse(std::string str)
{

    if(str[0] != '\0')
    {
       return reverse(str.substr(1,str.length())) + str[0];

    }
    else return "";



}