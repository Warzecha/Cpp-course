//
// Created by warzecha on 26.04.18.
//

#include "StudentRepository.h"


namespace academia
{

    StudentRepository::StudentRepository(const std::initializer_list<Student> initializer_list) {

        studentCount = initializer_list.size();

        for (const auto &student : initializer_list) {

            map.insert(std::make_pair(student.Id(), student));

        }

    }

    Student &StudentRepository::operator[](const std::string &_id) {
        return (*map.find(_id)).second;
    }

    unsigned long StudentRepository::StudentCount() const {
        return studentCount;
    }


    bool StudentRepository::operator==(const StudentRepository &rhs) const {
        return map == rhs.map;
    }

    StudentRepository::StudentRepository() {
        studentCount = 0;
    }

    std::vector<Student> StudentRepository::FindByQuery(const Query &query) {
        std::vector<Student> accepted;

        for(const auto &s : map)
        {
            if (query.Accept(s.second))
            {
                accepted.push_back(s.second);
            }
        }
        return accepted;
    }

    std::vector<Student> StudentRepository::FindByQuery(std::unique_ptr<Query> query) {
        std::vector<Student> accepted;

        for(const auto &s : map)
        {
            if (query->Accept(s.second))
            {
                accepted.push_back(s.second);
            }
        }
        return accepted;
    }

}