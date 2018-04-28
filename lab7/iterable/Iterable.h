//
// Created by warzecha on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H


#include <string>
#include <vector>

namespace utility
{


    class IterableIterator {

    public:



        virtual std::pair<int, std::string> Dereference() const = 0;


        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const IterableIterator &other) const = 0;

        virtual ~IterableIterator() = default;

    };



    class ZipperIterator : public IterableIterator
    {

    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);


        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override ;
        bool NotEquals(const IterableIterator &other) const override;

    private:

        std::vector<int>::const_iterator left;
        std::vector<std::string>::const_iterator right;
        std::vector<int>::const_iterator left_end;
        std::vector<std::string>::const_iterator right_end;


    };


    class Enumerate : public IterableIterator
    {
    public:
        Enumerate(std::vector<std::string> vs);

        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next();
        bool NotEquals(const IterableIterator &other) override;

    private:
        std::vector<std::string>::const_iterator it;
        std::vector<std::string>::const_iterator end;
        unsigned int index;
    };


}



#endif //JIMP_EXERCISES_ITERABLE_H
