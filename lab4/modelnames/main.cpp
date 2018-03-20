//
// Created by torzmich on 20.03.18.
//
//#include "ModelNames.h"c
#include <iostream>
#include <string>

int main() {

    std::string name = "adaaw weq dsa";
    int spaces = 0;

    for(int i = 0; name[i]!= '\0'; i++) {
        if(name[i] == ' ')
            spaces++;
    }
    std::cout<<spaces;

    return 0;
}