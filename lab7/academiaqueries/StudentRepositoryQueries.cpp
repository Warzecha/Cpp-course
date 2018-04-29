//
// Created by damian on 29.04.18.
//


#include <memory>
#include "StudentRepositoryQueries.h"


namespace academia
{


    bool ByFirstName::Accept(const Student &student) const {
        return student.FirstName() == first_name;
    }

    ByFirstName::ByFirstName(const std::string &name) : first_name(name) {}


    ByLastName::ByLastName(const std::string &name) : last_name(name) { }

    bool ByLastName::Accept(const Student &student) const {
        return student.LastName() == last_name;
    }



    bool ByOneOfPrograms::Accept(const Student &student) const {
        return programs.find(student.Program()) != programs.end();
    }

    ByOneOfPrograms::ByOneOfPrograms(std::initializer_list<std::string> initializer_list) {

        for(const auto &p : initializer_list)
        {
            programs.emplace(p);
        }
    }



    bool ByYearLowerOrEqualTo::Accept(const Student &student) const {
        return student.Year() <= year;
    }

    ByYearLowerOrEqualTo::ByYearLowerOrEqualTo(StudyYear year) : year(year){    }

    AndQuery::AndQuery(std::unique_ptr<Query> _left, std::unique_ptr<Query> _right) {

        left = std::move(_left);
        right = std::move(_right);

    }

    bool AndQuery::Accept(const Student &student) const {
        return left->Accept(student) && right->Accept(student);
    }

    OrQuery::OrQuery(std::unique_ptr<Query> _left, std::unique_ptr<Query> _right) {
        left = std::move(_left);
        right = std::move(_right);
    }

    bool OrQuery::Accept(const Student &student) const {
        return left->Accept(student) || right->Accept(student);
    }
}