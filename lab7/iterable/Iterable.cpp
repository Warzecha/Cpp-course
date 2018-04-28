//
// Created by warzecha on 22.04.18.
//

#include "Iterable.h"

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                        std::vector<std::string>::const_iterator right,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {


    this->left = left;
    this->right = right;
    this->left_end = left_end;
    this->right_end = right_end;
}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::make_pair(*left, *right);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    if(left == left_end || right == right_end)
        return *this;

    ZipperIterator new_iterator(left + 1, right + 1, left_end, right_end);
    return new_iterator;
}

bool utility::ZipperIterator::NotEquals(const utility::IterableIterator &other) const {
    ZipperIterator *o = dynamic_cast<ZipperIterator*>(&other);
    if (o) {
        return
                (left == o->left && *right == pair.second);
    } else return true;
}



std::pair<int, std::string> utility::Enumerate::Dereference() const {
    return std::make_pair(index, *it);
}

utility::IterableIterator &utility::Enumerate::Next() {



}

utility::Enumerate::Enumerate(std::vector<std::string> vs) {
    it = vs.begin();
    end = vs.end();
    index = 0;
}

bool utility::Enumerate::NotEquals(const utility::IterableIterator &other) {
    return false;
}
