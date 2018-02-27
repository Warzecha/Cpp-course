//
// Created by mwypych on 02.02.17.
//

#include "Factorial.h"
#include <cmath>

int factorial(int value) {

  if (value == 0 || value == 1)
    return 1;
  else if (value == -1)
    return -1;
  else if (value >= 13) return 0;
  else return (value>0) ? value * factorial(value-1) : value * factorial(value + 1);
  //if(value == 0)
  //  return 1;
  //else
  //  return tgamma(value)* value;

}
