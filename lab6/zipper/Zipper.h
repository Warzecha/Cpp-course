//
// Created by torzmich on 10.04.18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include "vector"
#include "iostream"
#include "string"


namespace datastructures
{

    class ZipperIterator {
    public:

        explicit ZipperIterator(std::pair <std::string, int> *ptr);

        std::pair<std::string,int> operator*() const; //wmagane w linii 74
        ZipperIterator &operator++(); //wymagane w linii 73 for(_;_;TU)
        bool operator!=(const ZipperIterator &other) const; //wymagane w linii 73 for(_;TU;_)
    private:

        std::pair <std::string, int> *ptr;


    };

//umożliwia przeglądanie dwóch wektorów na raz, w jednej pętli range-for
    class Zipper {
    public:
        static Zipper zip(const std::vector<std::string> &vs, const std::vector<int> &vi);

        ZipperIterator begin(); //wymagane w linii 73 for(TU;_;_)
        ZipperIterator end(); //wymagane w linii 73 for(_;TU;_)
    private:



        std::vector<std::pair<std::string, int>> vector;


//    ZipperIterator _begin;
//    ZipperIterator _end;


    };


}


#endif //JIMP_EXERCISES_ZIPPER_H
