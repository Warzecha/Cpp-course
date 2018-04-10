//
// Created by damian on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <ostream>
#include "StudyYear.h"

namespace academia
{

    class Student {
    public:
        Student(const std::string &id, const std::string &first_name, const std::string &last_name,
                const std::string &program, const StudyYear &studyYear);

        Student(const std::string &id, const std::string &first_name, const std::string &last_name,
                const std::string &program, const int studyYear);

        Student();

        bool operator==(const Student &rhs) const;

        bool operator!=(const Student &rhs) const;

        friend std::ostream &operator<<(std::ostream &os, const Student &student);

        const std::string &Id() const;

        const std::string &FirstName() const;

        const std::string &LastName() const;

        const std::string &Program() const;

        const StudyYear &Year() const ;

        void ChangeLastName(std::string new_name);



    private:

        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear studyYear;


    };
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
