//
// Created by damian on 20.03.18.
//

#include <iostream>
#include "SimpleUrl.h"

nets::SimpleUrl::SimpleUrl(std::string str) {

    std::cmatch m;


    //^([A-Za-z]+):(\/{2})?([A-Za-z0-9]*:)?([A-Za-z0-9]*@)?([A-Za-z0-9.]*)(:[0-9]+)?(\/[A-Za-z0-9%\/\.-]+)

    //to dobre
    //^([A-Za-z]+):(\/{2})?([A-Za-z0-9]*:)?([A-Za-z0-9]*@)?([A-Za-z0-9.-]*)(:[0-9]+)?(\/[A-Za-z0-9%\/\.\,_\@=:!-]*)?(\?[A-Za-z0-9%\/\.\,_\@=!-&]*)?(#[A-Za-z0-9%\/\.\,_\@=!-]*)?


    std::regex expresion("^([A-Za-z]+):(\\/{2})?([A-Za-z0-9]*:)?([A-Za-z0-9]*@)?([A-Za-z0-9.-]*)(:[0-9]+)?(\\/[A-Za-z0-9%\\/\\.\\,_\\@=:!-]*)?(\\?[A-Za-z0-9%\\/\\.\\,_\\@=!-&]*)?(#[A-Za-z0-9%\\/\\.\\,_\\@=!-]*)?");


    const char * str2 = str.c_str();

    std::regex_match(str2, m, expresion);

    std::string tmp;

    this->scheme = m[1];

    tmp = m[4];
    tmp = tmp.substr(0, tmp.size()-1);
    this->login = tmp;
    this->host = m[5];

    tmp = m[6];

    tmp.erase(0,1);
    if(tmp.size() > 0)
        this->port = static_cast<uint16_t>(std::stoi(tmp));
    else
    {
        if(this->scheme == "http")
            this->port = 80;
        else if(this->scheme == "https")
            this->port = 443;
        else if(this->scheme == "ftp")
            this->port = 22;
        else this->port = 0;
    }

    tmp = m[7];
    tmp.erase(0,1);
    this->path = tmp;


    tmp = m[8];
    tmp.erase(0,1);
    this->query = tmp;

    tmp = m[9];
    tmp.erase(0,1);
    this->fragment = tmp;


    //delete(str2);

}

nets::SimpleUrl::~SimpleUrl() {
//    delete(&scheme);
//    delete(&login);
//    delete(&fragment);
//    delete(&query);
//    delete(&port);
//    delete(&host);


}
