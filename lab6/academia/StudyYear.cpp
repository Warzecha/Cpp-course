//
// Created by damian on 10.04.18.
//

#include "StudyYear.h"

namespace academia{

    StudyYear::StudyYear(int year) : year(year) {}

    StudyYear::StudyYear(): year(1) {}

    int StudyYear::operator++() {
        year++;
        return year;
    }

    int StudyYear::operator--() {
        year--;
        return year;
    }

    bool StudyYear::operator==(const StudyYear &rhs) const {
        return year == rhs.year;
    }

    bool StudyYear::operator!=(const StudyYear &rhs) const {
        return !(rhs == *this);
    }

    std::ostream &operator<<(std::ostream &os, const StudyYear &year) {
        os << year.year;
        return os;
    }

    bool StudyYear::operator<(const StudyYear &rhs) const {
        return year < rhs.year;
    }

    bool StudyYear::operator>(const StudyYear &rhs) const {
        return rhs < *this;
    }

    bool StudyYear::operator<=(const StudyYear &rhs) const {
        return !(rhs < *this);
    }

    bool StudyYear::operator>=(const StudyYear &rhs) const {
        return !(*this < rhs);
    }

    StudyYear::operator int() const {
        return year;
    }




}


