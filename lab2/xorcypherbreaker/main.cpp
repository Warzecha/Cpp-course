//
// Created by damian on 11.03.18.
//

#include <iostream>
#include "XorCypherBreaker.h"

int main()
{
    std::string key = "aaa";

    while (generateNextKey(key)[0] <= 'z')
    {
        key = generateNextKey(key);
        std::cout<<key<<std::endl;

    }



    return 0;
}