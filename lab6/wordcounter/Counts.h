//
// Created by damian on 13.04.18.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures
{

    class Counts {
    public:
        Counts(unsigned int counts);

        unsigned int getCounts() const;

        void setCounts(unsigned int counts);

        bool operator<(const Counts &rhs) const;

        bool operator==(const Counts &rhs) const;

        bool operator!=(const Counts &rhs) const;

        bool operator>(const Counts &rhs) const;

        bool operator<=(const Counts &rhs) const;

        bool operator>=(const Counts &rhs) const;

        void operator++();

    private:
        unsigned int counts = 0;

    };
}




#endif //JIMP_EXERCISES_COUNTS_H
