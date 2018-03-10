//
// Created by misiu on 10.03.18.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Polybius.h"

int main(int argc, char* argv[]) {

    std::ifstream rFile(argv[1]);
    std::ofstream wFile(argv[2]);

    char* status = argv[3];
    std::cout<<(int)*status<<std::endl;
    int stat;
    if((int)*status == 49)
        stat = 1;
    else stat =0;




    if(!rFile)
        std::cout<<"Nie mozna otworzyc pliku rFile"<<std::endl;
    if(!wFile)
        std::cout<<"Nie mozna otworzyc pliku wFile"<<std::endl;

    std::string message;
    rFile >> message;
    std::string answer;


    if(stat) {
        answer = PolybiusCrypt(message);
        std::cout << answer;
    }
    else {
        std::cout<<"ELO";
        answer = PolybiusDecrypt(message);
        std::cout << answer;
    }

    wFile << answer;

    rFile.close();
    wFile.close();




    return 0;
}