//
// Created by torzmich on 27.03.18.
//

#include <TextPool.h>

using namespace pool;

int main() {

    TextPool pool = {"babka", "ciotka", "matka", "prababka"};

    auto s1 = pool.Intern("babka");

    auto s2 = pool.Intern("babka")



    return 0;
}