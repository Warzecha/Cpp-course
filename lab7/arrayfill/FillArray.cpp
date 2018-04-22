//
// Created by warzecha on 22.04.18.
//

#include <random>
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











    void FillArray(int size, ArrayFiller &arrayFill, std::vector<int> *vector) {

        vector->resize(size);

        for (int i = 0; i < size; ++i) {

            (*vector)[i] = arrayFill.Value(i);

        }

    }


    SquaredFill::SquaredFill(int a, int b) : a(a), b(b) { }

    int SquaredFill::Value(int index) {
        return a*index*index + b;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator,
                           std::unique_ptr<std::uniform_int_distribution<int>> distribution) {

        engine = std::move(generator);
        this->distribution = std::move(distribution);

    }

    int RandomFill::Value(int index) {
        int x = (*distribution)(*engine);
        return x;
    }


}
