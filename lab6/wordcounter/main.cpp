//
// Created by damian on 14.04.18.
//
#include "WordCounter.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace datastructures;

int main()
{

    WordCounter wc;
    std::ifstream myfile ("example.txt");

    std::istringstream iss("ala ma kota");


    std::istringstream s1("ala ma kota kota nota");
    std::istream s2(s1.rdbuf());






}