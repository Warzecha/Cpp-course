//
// Created by torzmich on 13.03.18.
//
#include "TinyUrl.h"

std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

    std::string longUrl = url;
    std::string shortUrl = "www.tinyurl/";
    longUrl = longUrl.substr(4);
    std::string toCode;

    for(char c : longUrl) {
        if(c != '.' && c != '/')
            toCode += c;
    }
    std::cout<<toCode;

}

std::unique_ptr<TinyUrlCodec> Init() {

}

void NextHash(std::array<char, 6> *state) {

}

std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

}
