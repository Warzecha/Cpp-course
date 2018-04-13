//
// Created by damian on 13.04.18.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>


namespace datastructures
{
    class Word {
    public:
        explicit Word(const std::string &word);

        bool operator<(const Word &rhs) const;

        bool operator>(const Word &rhs) const;

        bool operator<=(const Word &rhs) const;

        bool operator>=(const Word &rhs) const;

        bool operator==(const Word &rhs) const;

        bool operator!=(const Word &rhs) const;


    private:
        std::string word;

    };

}



#endif //JIMP_EXERCISES_WORD_H
