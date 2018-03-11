//
// Created by misiu on 10.03.18.
//

#include "Polybius.h"

std::string PolybiusCrypt(std::string message){

    std::string answer;

    char polybiusSquare[5][5];
    int ascii = 0;
    for(int i = 0; i<5; i++){
        for (int j = 0; j < 5; ++j) {
            if(ascii == 16)
                ascii++;
            polybiusSquare[i][j] = 'A' + ascii;
            std::cout<<polybiusSquare[i][j];
            ascii++;
        }
        std::cout<<std::endl;
    }

    for (char c : message) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                    if (c == polybiusSquare[i][j]) {
                        answer += std::to_string(i+1);
                        answer += std::to_string(j+1);
                        answer += " ";
                    }
            }

            }

        }


    return answer;
}

std::string PolybiusDecrypt(std::string message){

    std::string answer;

    std::string polybiusSquare[5][5];
    int ascii = 0;
    for(int i = 0; i<5; i++) {
        for (int j = 0; j < 5; ++j) {
            if (ascii == 16)
                ascii++;
            polybiusSquare[i][j] = 'A' + ascii;
            ascii++;
        }
    }

    for(int i = 0; message[i+2] != '\0'; i++) {
        if(message[i]!= ' ' && message[i+1]!=' '){
            answer += polybiusSquare[(int)message[i]-49][(int)message[i+1]-49];
        }
    }

    return answer;
}