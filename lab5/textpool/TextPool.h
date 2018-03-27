//
// Created by torzmich on 27.03.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H


#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

#include <vector>

namespace pool {

    class TextPool {
    public:

        TextPool();

        TextPool(std::initializer_list<std::string> &words);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:

        std::vector<std::string> words;


    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
