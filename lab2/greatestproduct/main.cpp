//
// Created by damian on 12.03.18.
//

#include <iostream>
#include "GreatestProduct.h"


int main()
{

    std::vector<int> numbers;

    numbers.push_back(-17);
    numbers.push_back(3);
    numbers.push_back(-1);



    std::cout<<GreatestProduct(numbers,2);




    return 0;
}
