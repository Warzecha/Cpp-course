//
// Created by damian on 12.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <map>
#include "Student.h"
#include "StudyYear.h"

namespace academia {
    class StudentRepository {

    public:

        StudentRepository (std::initializer_list<Student> initializer_list);

        Student &operator[](const std::string & _id);

        unsigned long StudentCount() const ;


    private:

        unsigned long studentCount = 0;
        std::map< std::string, Student> map;


    };
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
