//
// Created by damian on 12.04.18.
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


}


