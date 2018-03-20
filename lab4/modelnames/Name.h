//
// Created by torzmich on 20.03.18.
//

#ifndef JIMP_EXERCISES_MODELNAMES_H
#define JIMP_EXERCISES_MODELNAMES_H

#include <iostream>
#include <experimental/optional>

class Name {
public:
    Name(std::string firstName, std::string surname);

    Name(std::string name);

    const std::string &getFirstName() const;

    const std::string &getSurname() const;

    const std::string &getSecondName() const;

    const std::string &getThirdName() const;

    void setFirstName(const std::string &firstName);

    void setSurname(const std::string &surname);

    void setSecondName(const std::string &secondName);

    void setThirdName(const std::string &thirdName);

    std::string ToFullInitials();

    std::string ToFirstNamesInitials();

    std::string ToSurnameNames();

    std::string ToNamesSurname();

    bool IsBeforeBySurname(std::string surname);

    bool IsBeforeByFirstName(std::string firstname);

private:
    std::string firstName;
    std::string surname;
    std::string secondName;
    std::string thirdName;

};


#endif //JIMP_EXERCISES_MODELNAMES_H
