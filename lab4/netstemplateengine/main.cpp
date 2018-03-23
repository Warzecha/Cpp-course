//
// Created by damian on 20.03.18.
//
#include <iostream>
#include "SimpleTemplateEngine.h"

int main()
{
    nets::View templ("Ala ma {{zwierze}}  {{skop}}  sdffds");


    std::cout<<templ.Render({{"skop", "elo"}});




    return 0;
}

