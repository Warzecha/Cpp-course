#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

int main() {


    //std::string string1 = R"(\\\\\\\"http:\\\\\\\"klmno)"s;
    //std::string string2 = R"("\\\\\\\\\\\\\\\"http:\\\\\\\\\\\\\\\"klmno")"s;
    std::string string3 = R"("abc")"s;
    std::string string4 = R"(efg"hjk")"s;




    std::cout<<string3<<std::endl;
    nets::JsonValue val(string3);
    std::cout<<val.ToString()<<std::endl;

    //std::cout << string2;

    //std::cout << std::to_string(val.ToString() == string2);

}