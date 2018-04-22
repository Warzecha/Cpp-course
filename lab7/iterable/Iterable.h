//
// Created by warzecha on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H


#include <string>

class IterableIterator {

public:


    virtual std::pair<int, std::string> Dereference() = 0;
    virtual IterableIterator &Next() = 0;
    virtual bool NotEquals(const IterableIterator &other) = 0;

    ~IterableIterator() = default;

};


#endif //JIMP_EXERCISES_ITERABLE_H
