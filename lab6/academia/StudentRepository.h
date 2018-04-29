//
// Created by warzecha on 26.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <vector>
#include <StudentRepositoryQueries.h>
#include "Student.h"


namespace academia
{
    class StudentRepository {

    public:

        StudentRepository (std::initializer_list<Student> initializer_list);

        StudentRepository();

        Student &operator[](const std::string & _id);

        unsigned long StudentCount() const ;

        bool operator==(const StudentRepository &rhs) const;
        std::vector<Student> FindByQuery(const Query &query);
        std::vector<Student> FindByQuery(std::unique_ptr<Query> query);

    private:

        unsigned long studentCount = 0;
        std::map< std::string, Student> map;


    };

}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
