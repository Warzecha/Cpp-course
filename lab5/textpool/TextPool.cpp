//
// Created by torzmich on 27.03.18.
//

#include "TextPool.h"

using namespace pool;

size_t TextPool::StoredStringCount() const {
    return words.size();
}

std::experimental::string_view TextPool::Intern(const std::string &str) {

    bool isPresent = false;
    int wordI = 0;
    if(StoredStringCount() == 0) {
        words.push_back(str);
        return &words[0];
    }
    else {
        for (std::vector::iterator i = words.begin(); i != words.end(); i++) {
            if (str == words[i]) {
                isPresent = true;
                break;
            }
            wordI++;
        }

        if (!isPresent) {
            words.push_back(str);
            return &words[words.size() - 1];
        }
        else
            return &words[wordI];
    }
}

TextPool::TextPool(std::initializer_list<std::string> &words) : words(words) {};