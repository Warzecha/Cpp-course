//
// Created by damian on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H


#include <ostream>

namespace academia{

    class StudyYear {
    public:


        StudyYear(int year);
        StudyYear();
        int operator++();
        int operator--();

        bool operator==(const StudyYear &rhs) const;

        bool operator!=(const StudyYear &rhs) const;

        friend std::ostream &operator<<(std::ostream &os, const StudyYear &year);

        bool operator<(const StudyYear &rhs) const;

        bool operator>(const StudyYear &rhs) const;

        bool operator<=(const StudyYear &rhs) const;

        bool operator>=(const StudyYear &rhs) const;

        operator int () const ;

    private:
        int year;

    };
}




#endif //JIMP_EXERCISES_STUDYYEAR_H
