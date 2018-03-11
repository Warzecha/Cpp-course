//
// Created by misiu on 10.03.18.
//

#include "Polybius.h"

//std::string PolybiusCrypt(std::string message){
//
//    std::string answer;
//
//    char polybiusSquare[5][5];
//    int ascii = 0;
//    for(int i = 0; i<5; i++){
//        for (int j = 0; j < 5; ++j) {
////            if(ascii == 16)
////                ascii++;
//            //polybiusSquare[i][j] = 'A' + ascii;
//            std::cout<<polybiusSquare[i][j];
//            ascii++;
//        }
//        std::cout<<std::endl;
//    }
//
//    for (char c : message) {
//        for (int i = 0; i < 5; ++i) {
//            for (int j = 0; j < 5; ++j) {
//                    if (c == polybiusSquare[i][j]) {
//                        answer += std::to_string(i+1);
//                        answer += std::to_string(j+1);
//                        answer += " ";
//                    }
//            }
//
//            }
//
//        }
//
//
//    return answer;
//}
//






std::string PolybiusDecrypt(std::string message){

    std::string answer = "";

    std::string polybiusSquare[5][5];
    int ascii = 0;
    for(int i = 0; i<5; i++) {
        for (int j = 0; j < 5; ++j) {
            if (ascii == 9)
                ascii++;
            polybiusSquare[i][j] = 'a' + ascii;
            ascii++;
        }
    }


    for (int k = 0; k < message.length(); k+=2) {

        int i = message[k] - '1';
        int j = message[k+1] - '1';


        answer += (polybiusSquare[i][j]);

    }

    return answer;
}

std::string PolybiusCrypt(std::string message) {

    std::string answer = "";

    for (auto x : message)
    {
        x = static_cast<char>(tolower(x));

        if (int(x) != 32)
        {
            int c = int(x);
            if (c >= 'J')
            {
                c--;
            }

            c -= 'A';
            c++;
            answer += std::to_string(int( (c-1)/5 +1));
            answer += std::to_string(int(c-1)%5 + 1);

        }


    }

    return answer;
}
