//
// Created by torzmich on 27.03.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H


#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <algorithm>

namespace pool {

    class TextPool {
    public:

        TextPool();

        TextPool(const std::initializer_list<const std::string > &words);

        TextPool( TextPool && other);
        TextPool &operator=(TextPool &&other);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

        virtual ~TextPool();

    private:

        std::set<std::string > set = {};


    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
