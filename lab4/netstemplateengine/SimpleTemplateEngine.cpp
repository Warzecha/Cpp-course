//
// Created by damian on 20.03.18.
//


#include <iostream>
#include "SimpleTemplateEngine.h"


std::string find_and_replace(const std::string &source, std::string const& find, std::string const& replace)
{
    std::string src_copy(source);
    for(std::string::size_type i = 0; (i = src_copy.find(find, i)) != std::string::npos;)
    {
        src_copy.replace(i, find.length(), replace);
        i += replace.length();
    }
    return src_copy;
}





nets::View::View(const std::string &object_template) : object_template(object_template) {}

std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {

    std::string str_copy = this->object_template;
    std::vector<std::string> replace_vector;
    std::cmatch match;

    std::regex injection("\\{\\{\\w*\\}\\}");




    for(auto m : model)
    {
        std::string to_find = "{{"+m.first+"}}";
        std::string to_replace = m.second;
        if(std::regex_match(to_replace.begin(), to_replace.end(), injection))
        {
            replace_vector.push_back(to_replace);
            to_replace = "{{"+ std::to_string(replace_vector.size() - 1) + "}}";
        }
        str_copy = find_and_replace(str_copy,to_find, to_replace);
    }




    const char * str = str_copy.c_str();
    std::regex expresion_with_brackets(".*(\\{\\{[A-Za-z_][A-Za-z0-9_]*\\}\\}).*");
    std::cmatch m;

    //std::cout << str;

    //std::regex_match(str, m, expresion_with_brackets);

    while(std::regex_match(str, m, expresion_with_brackets))
    {

        //std::cout<<m[0].str()<<std::endl;
        str_copy = find_and_replace(str_copy,m[1].str(), "");
        str = str_copy.c_str();


    }

    str_copy = str;

    for (int i = 0; i < replace_vector.size(); ++i) {

        std::string to_find = "{{" + std::to_string(i) + "}}";
        std::string to_replace = replace_vector[i];
        str_copy = find_and_replace(str_copy,to_find, to_replace);
    }



    return str_copy;
}
