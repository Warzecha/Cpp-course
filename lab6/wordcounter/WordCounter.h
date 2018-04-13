//
// Created by damian on 12.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <map>
#include "Counts.h"
#include "Word.h"

namespace datastructures
{

    class WordCounter {
    public:

        WordCounter(const std::initializer_list<Word> initializer_list);
        WordCounter();

        int DistinctWords() const ;
        int TotalWords() const ;

        int operator[](std::string to_find) const ;

        std::set<Word> Words() const ;



    private:
        std::map<datastructures::Word, Counts> dictionary;


    };


}




#endif //JIMP_EXERCISES_WORDCOUNTER_H
