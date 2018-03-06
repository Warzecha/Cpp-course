//
// Created by mwypych on 02.02.17.
//

#include "Factorial.h"
#include <cmath>
#include <iostream>

bool OutOfRange(int value);

int Factorial(int value) {

  if (OutOfRange(value)) {
    std::cout<<"Out of range"<<std::endl;
    return 0;
  } else if (value == 0 || value == 1)
    return 1;
  else if (value == -1)
    return -1;
  else return (value > 0) ? value * Factorial(value - 1) : value * Factorial(value + 1);


}

bool OutOfRange(int value) { return value <= -13 || value >= 13; }
