//
// Created by warzecha on 22.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <memory>
#include <random>
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
        IncrementalFill(int start, int step = 1);

        int Value(int index) override;

    private:
        int start;
        int step;

    };

    class SquaredFill : public ArrayFiller
    {

    public:
        SquaredFill(int a = 1, int b = 0);
        int Value(int index) override;


    private:
        int a;
        int b;



    };



    class RandomFill : public ArrayFiller
    {
    public:


        RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution);

        int Value(int index) override;

    private:

        std::unique_ptr<std::default_random_engine> engine;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution;

    };


    void FillArray(int size, ArrayFiller &arrayFill, std::vector<int> *vector);


}




#endif //JIMP_EXERCISES_ARRAYFILL_H
