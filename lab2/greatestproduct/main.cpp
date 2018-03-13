//
// Created by damian on 12.03.18.
//

#include <iostream>
#include "GreatestProduct.h"


int main()
{

    std::vector<int> numbers;

    numbers.push_back(-2);
    numbers.push_back(2);
    numbers.push_back(-3);



    std::cout<<GreatestProduct(numbers,2);




    return 0;
}
