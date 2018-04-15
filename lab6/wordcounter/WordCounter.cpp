//
// Created by damian on 12.04.18.
//

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include "WordCounter.h"

namespace datastructures
{
    struct {
        bool operator()(std::pair<Word, Counts> a, std::pair<Word, Counts> b) const
        {
            return a.second < b.second;
        }
    } customLess;

    WordCounter::WordCounter() = default;

    WordCounter::WordCounter(const std::initializer_list<datastructures::Word> initializer_list) {


        for(auto w : initializer_list)
        {
            auto it = dictionary.find(w);
            if(it != dictionary.end())
            {
                (it->second).operator++();
            }
            else
            {
                auto pair = std::make_pair(w, Counts(1));
                dictionary.insert(pair);
            }
        }


    }

    int WordCounter::DistinctWords() const {
        return dictionary.size();
    }

    int WordCounter::TotalWords() const {
        int sum = 0;
        for(auto word : dictionary)
        {
            sum += word.second.getCounts();
        }

        return sum;
    }

    int WordCounter::operator[](std::string to_find) const {
        auto it = dictionary.find(datastructures::Word(to_find));

        if(it == dictionary.end())
        {
            return 0;
        }else
        {
            return it->second.getCounts();
        }
    }

    std::set<Word> WordCounter::Words() const {
        std::set<datastructures::Word> set;

        for (auto word : dictionary)
        {
            set.insert(word.first);
        }


        return set;
    }

    std::ostream &operator<<(std::ostream &os, const WordCounter &counter) {
        std::vector<std::pair<Word, Counts>> vec;

        for( auto w : counter.dictionary)
        {
            vec.push_back(w);
        }
        std::sort(vec.begin(), vec.end(), customLess);

        for (auto w : vec)
        {
            os << w.first.getWord() << " - " << w.second.getCounts() << std::endl;

        }



        return os;
    }

    std::vector<std::pair<Word, Counts>> WordCounter::FromInputStream(std::istream in) {

        std::string str;
        WordCounter wordCounter;

        while(in >> str)
        {
            in >> str;
            wordCounter.addWord(Word(str));
        }


        std::vector<std::pair<Word, Counts>> to_return;

        for( auto w : wordCounter.dictionary)
        {
            to_return.push_back(w);

        }


        return to_return;
    }

    void WordCounter::addWord(Word new_word) {

        auto it = dictionary.find(new_word);
        if(it != dictionary.end())
        {
            (it->second).operator++();
        }
        else
        {
            auto pair = std::make_pair(new_word, Counts(1));
            dictionary.insert(pair);
        }

    }


}


