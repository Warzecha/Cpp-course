//
// Created by damian on 13.03.18.
//

#include <iostream>
#include "MinimalTimeDifference.h"

int main()
{

    //"", ""}, 538
    int a = minimaltimedifference::ToMinutes("01:24");
    int b = minimaltimedifference::ToMinutes("10:22");

    std::cout << a << std::endl;
    std::cout << b << std::endl;



    return 0;
}