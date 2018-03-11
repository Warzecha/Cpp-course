//
// Created by misiu on 10.03.18.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Polybius.h"

int main(int argc, char* argv[]) {

//    std::ifstream rFile(argv[1]);
//    std::ofstream wFile(argv[2]);
//
//    char* status = argv[3];
//
//
//
//    if(!rFile)
//        std::cout<<"Nie mozna otworzyc pliku rFile"<<std::endl;
//    if(!wFile)
//        std::cout<<"Nie mozna otworzyc pliku wFile"<<std::endl;
//
//    std::string message((std::istreambuf_iterator<char>(rFile)), std::istreambuf_iterator<char>());
//    std::cout<<message<<std::endl;
//    std::string answer;
//
//    rFile.close();
//
//
//    if(*status == '1') {
//        answer = PolybiusCrypt(message);
//        std::cout << answer;
//    }
//    else {
//        std::cout<<"ELO"<<std::endl;
//        answer = PolybiusDecrypt(message);
//        std::cout << answer;
//    }
//
//    wFile << answer;
//    wFile.close();



    std::cout<<PolybiusDecrypt("11");






    return 0;
}