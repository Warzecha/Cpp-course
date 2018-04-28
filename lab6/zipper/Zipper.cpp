//
// Created by torzmich on 10.04.18.
//

#include "Zipper.h"
#include "vector"
#include "algorithm"
#include "iostream"



ZipperIterator &ZipperIterator::operator++() {
    ptr++;

    return *this;
}

bool ZipperIterator::operator!=(const ZipperIterator &other) const {
    return ptr != other.ptr;
}

ZipperIterator::ZipperIterator(std::pair<std::string, int> *_ptr) {
    ptr = _ptr;

}



ZipperIterator Zipper::begin() {
    return _begin;
}

ZipperIterator Zipper::end() {
    return _end;
}

Zipper Zipper::zip(const std::vector<std::string> &vs, const std::vector<int> &vi) {
    auto * new_zipper = new Zipper;


    new_zipper->vector.resize(std::max(vs.size(), vi.size()));

    int i = 0;
     for( auto x : vi)
     {
         new_zipper->vector[i].second = x;


         i++;
     }

    i = 0;
    for( auto x : vs)
    {
        new_zipper->vector[i].first = x;

        i++;
    }



    //Do poprawy

    new_zipper->_begin;



    return Zipper();
}
