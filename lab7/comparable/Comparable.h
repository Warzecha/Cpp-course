//
// Created by warzecha on 22.04.18.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H


#include "../../lab6/academia/Student.h"

namespace academia
{
    class Comparable {

    public:
        virtual bool IsLess(const Student &left, const Student &right) = 0;
        virtual bool operator()(const Student &left, const Student &right) = 0;

    };



    class ByFirstNameAscending
    {
    public:
        bool IsLess(const Student &left, const Student &right);
        bool operator()(const Student &left, const Student &right);
    };


    class ByFirstNameDescending
    {
    public:
        bool IsLess(const Student &left, const Student &right);
        bool operator()(const Student &left, const Student &right);
    };

    class ByLastNameAscending
    {
    public:
        bool IsLess(const Student &left, const Student &right);
        bool operator()(const Student &left, const Student &right);
    };

    class ByProgramAscendingEmptyFirst
    {
    public:
        bool IsLess(const Student &left, const Student &right);
        bool operator()(const Student &left, const Student &right);
    };

    class ByProgramAscendingEmptyLast
    {
    public:
        bool IsLess(const Student &left, const Student &right);
        bool operator()(const Student &left, const Student &right);
    };


}





#endif //JIMP_EXERCISES_COMPARABLE_H
