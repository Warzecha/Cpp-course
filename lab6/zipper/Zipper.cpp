//
// Created by torzmich on 10.04.18.
//

#include "Zipper.h"
#include "vector"
#include "algorithm"
#include "iostream"

int foo(const std::vector<std::string> &v1, const std::vector<int> &v2) {
    for (const std::pair<std::string,int> &p : Zipper::zip(v1,v2)) {
        if (p.first == "elo") {
            return p.second+4;
        }
    }
    return 0;
}


Zipper::Zipper(std::vector<std::string> text, std::vector<int> value) {
    this->text = text;
    this->value = value;
}

Zipper::~Zipper() {}
Zipper::Zipper() {}
Zipper::Zipper(int begin, int end) {
    this->begin = begin;
    this->end = end;
}

Zipper Zipper::ZipperIterator(std::vector<std::string> text, std::vector<int> value) {
    int bigger = std::max(text.size(), value.size());
    std::vector::iterator = 
    return Zipper(0,bigger-1);
}

static Zipper Zipper::zip(std::vector<std::string> text, std::vector<int> value) {
    return ZipperIterator(text, value);
}