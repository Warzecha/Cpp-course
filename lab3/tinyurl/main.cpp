//
// Created by torzmich on 13.03.18.
//
#include <iostream>
int main() {

    std::string longUrl = "www.abc.com/alfabet";
    longUrl = longUrl.substr(4);
    std::string shortUrl;
    std::string toCode;

    for(char c : longUrl) {
        if(c != '.' && c != '/')
            toCode += c;
    }
    std::cout<<toCode;


    return 0;
}