//
// Created by damian on 29.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H


#include <memory>
#include <set>
#include <Student.h>


namespace academia
{
    class Query {


    public:
        virtual bool Accept(const Student &student) const = 0;

    };



    class ByFirstName : public Query
    {

    public:


        ByFirstName(const std::string &name);

        bool Accept(const Student &student) const override;

    private:

        std::string first_name;
    };


    class ByLastName : public Query
    {

    public:


        ByLastName(const std::string &name);

        bool Accept(const Student &student) const override;

    private:

        std::string last_name;
    };


    class ByOneOfPrograms : public Query
    {
    public:
        ByOneOfPrograms(std::initializer_list<std::string> initializer_list);

        bool Accept(const Student &student) const override;


    private:

        std::set<std::string> programs;

    };

    class ByYearLowerOrEqualTo : public Query
    {
    public:
        explicit ByYearLowerOrEqualTo(StudyYear year);
        bool Accept(const Student &student) const override;

    private:
        StudyYear year;

    };


    class AndQuery : public Query
    {
    public:

        AndQuery(std::unique_ptr<Query> left, std::unique_ptr<Query> right);
        bool Accept(const Student &student) const override;


    private:
        std::unique_ptr<Query> left;
        std::unique_ptr<Query> right;
    };

    class OrQuery : public Query
    {
    public:

        OrQuery(std::unique_ptr<Query> left, std::unique_ptr<Query> right);
        bool Accept(const Student &student) const override;


    private:
        std::unique_ptr<Query> left;
        std::unique_ptr<Query> right;
    };


}





#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
