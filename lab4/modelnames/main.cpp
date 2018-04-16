//
// Created by torzmich on 20.03.18.
//
#include "Name.h"
#include <memory>

using namespace model;
int main() {


    Name imie {"First\t\tAndSecond\n\r \tSurname"};
    try
    {
        std::cout<< imie.SecondName().value();
    }

    catch(int e)
    {
        std::cout<<"err: "<<e;
    }





}