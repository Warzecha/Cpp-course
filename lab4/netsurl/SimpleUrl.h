//
// Created by damian on 20.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H


#include <cstdint>
#include <string>
#include <regex>


namespace nets {

    class SimpleUrl {
    public:

        SimpleUrl(std::string str);




        std::string Login() const {
            return this->login;
        }

        std::string Host() const {
            return this->host;
        }

        std::string Path() const {
            return this->path;
        }

        uint16_t Port() const {
            return this->port;
        }

        std::string Scheme() const {
            return this->scheme;
        }

        std::string Query() const {
            return this->query;
        }

        std::string Fragment() const {
            return this->fragment;
        }

        virtual ~SimpleUrl();


    private:

        std::string login;
        std::string host;
        std::string path;
        uint16_t port;
        std::string scheme;
        std::string query;
        std::string fragment;



    };

}


#endif //JIMP_EXERCISES_SIMPLEURL_H
