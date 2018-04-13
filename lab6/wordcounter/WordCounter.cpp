//
// Created by damian on 12.04.18.
//

#include <set>
#include "WordCounter.h"

namespace datastructures
{


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


}


