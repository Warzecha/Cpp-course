//
// Created by damian on 13.04.18.
//

#include "Word.h"


namespace datastructures
{


    Word::Word(const std::string &word) : word(word) {}

    bool Word::operator<(const Word &rhs) const {
        return word < rhs.word;
    }

    bool Word::operator>(const Word &rhs) const {
        return rhs < *this;
    }

    bool Word::operator<=(const Word &rhs) const {
        return !(rhs < *this);
    }

    bool Word::operator>=(const Word &rhs) const {
        return !(*this < rhs);
    }

    bool Word::operator==(const Word &rhs) const {
        return word == rhs.word;
    }

    bool Word::operator!=(const Word &rhs) const {
        return !(rhs == *this);
    }

    const std::string &Word::getWord() const {
        return word;
    }
}