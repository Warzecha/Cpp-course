//
// Created by torzmich on 10.04.18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include "vector"
#include "iostream"
#include "string"


class Zipper {

public:
    Zipper();
    Zipper(std::vector<std::string> text, std::vector<int> value);
    ~Zipper();
    Zipper(std::vector::iterator begin, std::vector::iterator end;

    static Zipper zip(std::vector<std::string> text, std::vector<int> value);

    Zipper ZipperIterator(std::vector<std::string> text, std::vector<int> value);

private:
    std::vector<std::string> text;
    std::vector<int> value;
    std::vector::iterator begin;
    std::vector::iterator end;

};


#endif //JIMP_EXERCISES_ZIPPER_H
