//
// Created by warzecha on 22.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>

namespace arrays
{
    class ArrayFiller{


    public:
        virtual int Value(int index) = 0;

    };


    class UniformFill : public ArrayFiller{


        public:
        UniformFill(int val = 0);

        int Value(int index) override;

    private:
        int val;

    };


    class IncrementalFill : public ArrayFiller
    {
    public:
        IncrementalFill(int start, int step = 0);

        int Value(int index) override;

    private:
        int start;
        int step;

    };


    void ArrayFill(int size, ArrayFiller &arrayFill, std::vector<int> *vector);

}




#endif //JIMP_EXERCISES_ARRAYFILL_H
