//
// Created by damian on 10.04.18.
//


#include <iostream>
#include "StudentRepository.h"


int main()
{


    academia::StudentRepository repository;
//            {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
//             {"2035", "Orson", "Sabach", "górnictwo", 2}};


    std::cout << repository["2030"].FirstName();


}

