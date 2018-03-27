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


    std::string string1 = R"(\\"ghh\")"s;
    std::string string2;




    std::cout<<string1<<std::endl;
    nets::JsonValue val(string1);
    std::cout<<val.ToString()<<std::endl;

}