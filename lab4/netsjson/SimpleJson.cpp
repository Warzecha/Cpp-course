//
// Created by damian on 23.03.18.
//

#include <vector>
#include <map>
#include <iostream>
#include "SimpleJson.h"
using namespace ::std::literals;



namespace nets
{

std::string AddBackslash(std::string str)
{
    std::string temp;
    for (char i : str) {
        if(i =='\\' || i == '\"')
            temp+='\\';
        temp+= i;
    }
    return temp;
}







    JsonValue::JsonValue(int value) {
        this->integer = value;

    }

    JsonValue::JsonValue(double value) {
        this->floating_point = value;

    }

    JsonValue::JsonValue(std::string str) {
        this->str = str;
        //std::cout<<str<<std::endl;

    }

    JsonValue::JsonValue(bool value) {
        this->boolean = value;

    }
    JsonValue::JsonValue(const std::vector<JsonValue> &_vector) {
        this->vector = _vector;
    }
    JsonValue::JsonValue(const std::map<std::string, JsonValue> &obj_map) {
        this->map = obj_map;
    }

    std::string JsonValue::ToString() const {

        if(this->boolean)
        {
            if(this->boolean.value())
                return "true";
            else
                return "false";
        }

        if(this->integer)

            return std::to_string(this->integer.value());

        if(this->floating_point)
        {
            std::string str = std::to_string(this->floating_point.value());
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
            return str;
        }



        if(this->str)
        {
            return escapeString(str.value());

        }


        if(this->map)
        {
            std::string tmp;

            tmp += "{";

            for (auto x : this->map.value()) {

                tmp += escapeString(x.first) +": "  + x.second.ToString() +", " ;

            }
            tmp.erase(tmp.length()-2,2);


            tmp += "}";


            return tmp;


        }

        if(this->vector)
        {
            std::string tmp;
            tmp += "[";

            for (const auto &x : this->vector.value()) {

                tmp += x.ToString() + ", ";

            }


            tmp.erase(tmp.length()-2,2);

            tmp += "]";


            return tmp;
        }



    }

    std::string JsonValue::escapeString(std::string str) const {
        std::string temp;

        //std::cout << std::endl;;

        for(char c : str)
            {

                if( c == '\\' || c == '\?')
                    temp += "\\";

                temp += c;

            }


        return "\"" + temp + "\"";
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

        if(this->map)
        {
            auto it = this->map.value().find(name);
            if(it != this->map.value().end())
            {
                return it->second;
            }
            else return std::experimental::optional<JsonValue>();
        }


        return std::experimental::optional<JsonValue>();
    }

    JsonValue::JsonValue(const char *str) {
        this->str = std::string(str);
    }


}