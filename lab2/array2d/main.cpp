//
// Created by torzmich on 06.03.18.
//

#include "Array2D.h"
#include <iostream>

int main() {

    int ** tab;
    tab = Array2D(5,7);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cout<<tab[i][j]<<std::endl;

        }
    }

    DeleteArray2D(tab, 5,7);

    return 0;
}