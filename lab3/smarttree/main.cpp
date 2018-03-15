//
// Created by damian on 13.03.18.
//

#include <iostream>
#include "SmartTree.h"

using namespace datastructures;
int main()
{


    auto tree = RestoreTree("[-13 [none] [none]]");


    std::cout<< datastructures::DumpTree(tree);


    return 0;
}