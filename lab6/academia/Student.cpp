//
// Created by damian on 10.04.18.
//

#include "Student.h"

namespace academia
{
    bool Student::operator==(const Student &rhs) const {
        return id == rhs.id;
    }

    bool Student::operator!=(const Student &rhs) const {
        return !(rhs == *this);
    }

    std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student {id: " << student.id << " first_name: " << student.first_name << " last_name: " << student.last_name << " program: " << student.program <<" year: " << student.studyYear;
        return os;
    }



    Student::Student(const std::string &id, const std::string &first_name, const std::string &last_name,
                     const std::string &program, const StudyYear &studyYear) : id(id), first_name(first_name),
                                                                               last_name(last_name), program(program),
                                                                               studyYear(studyYear) {}

    Student::Student() {
        id = "";
        first_name = "";
        last_name = "";
        program = "";
        studyYear = StudyYear();


    }

    Student::Student(const std::string &id, const std::string &first_name, const std::string &last_name,
                     const std::string &program, const int studyYear) : id(id), first_name(first_name),
                                                                              last_name(last_name), program(program),
                                                                              studyYear(studyYear){ }

    const std::string &Student::Id() const {
        return id;
    }

    const std::string &Student::FirstName() const {
        return first_name;
    }

    const std::string &Student::LastName() const {
        return last_name;
    }

    const std::string &Student::Program() const {
        return program;
    }

    const StudyYear &Student::Year() const {
        return studyYear;
    }

    void Student::ChangeLastName(std::string new_name) {
        last_name = new_name;
    }


}

