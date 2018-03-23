//
// Created by damian on 23.03.18.
//

#include <vector>
#include <map>
#include "SimpleJson.h"



namespace nets
{


    JsonValue::JsonValue(int value) {
        this->integer = value;

    }

    JsonValue::JsonValue(float value) {
        this->floating_point = value;

    }

    JsonValue::JsonValue(std::string str) {
        this->str = str;

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
            return std::to_string(this->floating_point.value());

        if(this->str)
            return this->str.value();


    }




}