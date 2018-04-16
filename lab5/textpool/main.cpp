//
// Created by torzmich on 27.03.18.
//

#include <TextPool.h>
#include <iostream>

using namespace pool;

int main() {

    //"babka", "ciotka", "matka", "prababka"

    TextPool pool {"a", "b", "c", "aaa", "ld"};

//    auto s1 = pool.Intern("babka");
//
//    auto s2 = pool.Intern("babka")
//

    std::cout << pool.StoredStringCount();

    std::set<std::experimental::string_view > set {"a", "b", "c", "aaa", "ld"};

    std::cout << set.size();


    return 0;
}