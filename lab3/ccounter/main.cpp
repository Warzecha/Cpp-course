//
// Created by damian on 14.03.18.
//


#include "CCounter.h"



int main()
{

    std::unique_ptr<ccounter::Counter> c = ccounter::Init();
    ccounter::Inc("v", &c);


}