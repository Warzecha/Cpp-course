//
// Created by torzmich on 06.03.18.
//

#include "Array2D.h"

int ** NewArray(int rows, int cols) {

    int ** array = new int*[rows];
    for(int j = 0; j < cols; j++)
        array[j] = new int[cols];

    return array;
}

int ** Array2D(int rows, int cols) {

    int integer = 1;
    int ** array = NewArray(rows, cols);
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            array[i][j] = integer;
            integer ++;
        }
    }

    return array;

}

void DeleteArray2D(int **array, int rows, int cols) {
    for (int i = 0; i < rows ; i++) {
        delete array[i];
    }
    delete array;
}
