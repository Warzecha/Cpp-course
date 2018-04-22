//
// Created by warzecha on 22.04.18.
//

#include "FillArray.h"


namespace arrays
{

    arrays::UniformFill::UniformFill(int val) : val(val) {}

    int arrays::UniformFill::Value(int index) {
        return val;
    }


    IncrementalFill::IncrementalFill(int start, int step) : start(start), step(step) {}

    int IncrementalFill::Value(int index) {
        return start + index * step;
    }

    void ArrayFill(int size, ArrayFiller &arrayFill, std::vector<int> *vector) {

        for (int i = 0; i < size; ++i) {

            (*vector)[i] = arrayFill.Value(i);

        }

    }
}
