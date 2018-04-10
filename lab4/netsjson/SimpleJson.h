//
// Created by damian on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>



namespace nets{
    class JsonValue {

    public:


        JsonValue(int value);
        JsonValue(double value);
        JsonValue(std::string str);
        JsonValue(const char* str);

        JsonValue(bool value);
        JsonValue(const std::vector<JsonValue>& _vector);
        JsonValue(const std::map<std::string, JsonValue>& obj_map);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;


    private:


        std::experimental::optional <int> integer;
        std::experimental::optional <double> floating_point;
        std::experimental::optional <bool> boolean;
        std::experimental::optional <std::string> str;
        std::experimental::optional <std::vector<JsonValue>> vector;
        std::experimental::optional <std::map<std::string, JsonValue>> map;

    };


}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
