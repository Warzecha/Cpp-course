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
            ascii++;
        }
    }


        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (char &c : message) {
                    if (c == polybiusSquare[i][j])
                        answer += std::to_string(i);
                        answer += std::to_string(j);
                        answer += " ";
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

    for(std::string::iterator it = message.begin(); it != message.end(); it ++){
        if(*it != 32 || *(it+1) != 32){
            answer += polybiusSquare[int(*it)][int(*(it+1))];
        }

    }

    return answer;
}