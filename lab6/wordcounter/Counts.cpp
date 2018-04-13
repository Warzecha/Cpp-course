//
// Created by damian on 13.04.18.
//

#include "Counts.h"

namespace datastructures
{

    unsigned int Counts::getCounts() const {
        return counts;
    }

    void Counts::setCounts(unsigned int counts) {
        Counts::counts = counts;
    }

    bool Counts::operator<(const Counts &rhs) const {
        return counts < rhs.counts;
    }

    bool Counts::operator>(const Counts &rhs) const {
        return rhs < *this;
    }

    bool Counts::operator<=(const Counts &rhs) const {
        return !(rhs < *this);
    }

    bool Counts::operator>=(const Counts &rhs) const {
        return !(*this < rhs);
    }

    bool Counts::operator==(const Counts &rhs) const {
        return counts == rhs.counts;
    }

    bool Counts::operator!=(const Counts &rhs) const {
        return !(rhs == *this);
    }

    void Counts::operator++() {
        counts++;

    }

    Counts::Counts(unsigned int counts) : counts(counts) {}
}


