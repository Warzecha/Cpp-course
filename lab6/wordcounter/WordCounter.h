//
// Created by damian on 12.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <map>
#include <ostream>
#include <istream>
#include "Counts.h"
#include "Word.h"
#include <set>
#include <vector>

namespace datastructures
{

    class WordCounter {
    public:

        WordCounter(const std::initializer_list<Word> initializer_list);

        //friend std::ostream &operator<<(std::ostream &os, const WordCounter &counter);

        WordCounter();

        int DistinctWords() const ;
        int TotalWords() const ;

        void addWord(Word new_word);

        int operator[](std::string to_find) const ;

        std::set<Word> Words() const ;

        friend std::ostream &operator<<(std::ostream &os, const WordCounter &counter);
        static std::vector<std::pair<Word, Counts>> FromInputStream(std::istream in);

    private:
        std::map<datastructures::Word, Counts> dictionary;


    };


}




#endif //JIMP_EXERCISES_WORDCOUNTER_H
