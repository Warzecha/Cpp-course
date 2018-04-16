//
// Created by torzmich on 27.03.18.
//

#include "TextPool.h"

namespace pool
{



    TextPool::TextPool() {

    }

    size_t TextPool::StoredStringCount() const {
        return set.size();
    }

    TextPool::~TextPool() {
        set.clear();

    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {

//            set.emplace(std::experimental::string_view(str.c_str(),str.length()));
//            return *set.find(str);
        bool flag = true;
        for (auto &n : this->set) {
            if (n == str){
                flag = false;
                return n;
            }
        }
        if (flag){
            set.emplace(str);
            return Intern(str);
        }


    }


    TextPool::TextPool(const std::initializer_list<const std::string> &words) {

        for (const auto &word : words) {

            set.emplace(word);

        }
    }

    TextPool::TextPool(TextPool &&other) : set(other.set) {
        //std::swap(set, other.set);
        //std::swap(set, other.set);
        //other.set.clear();
        other.set.clear();
    }

    TextPool & TextPool::operator=(TextPool && other) {
        if(this!=&other) // prevent self-move
        {
            set.clear();
            set = other.set;
            other.set.clear();
        }
        return *this;
    }


}