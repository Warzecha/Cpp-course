//
// Created by torzmich on 20.03.18.
//

#ifndef JIMP_EXERCISES_MODELNAMES_H
#define JIMP_EXERCISES_MODELNAMES_H

#include <iostream>
#include <experimental/optional>

namespace model{

    class Name {
    public:
        Name(std::string firstName, std::string surname);

        Name(std::string name);

        std::string FirstName() const;
        std::experimental::optional<std::string> SecondName() const;
        std::experimental::optional<std::string> ThirdName() const;
        std::string Surname() const;

        void setFirstName(const std::string &firstName);

        void setSurname(const std::string &surname);

        void setSecondName(const std::string &secondName);

        void setThirdName(const std::string &thirdName);

        std::string ToFullInitials();

        std::string ToFirstNamesInitials();

        std::string ToSurnameNames();

        std::string ToNamesSurname();

        bool IsBeforeBySurname(Name &name);

        bool IsBeforeByFirstName(Name &name);

    private:
        std::string firstName;
        std::string surname;
        std::experimental::optional<std::string> secondName;
        std::experimental::optional<std::string> thirdName;

    };


}




#endif //JIMP_EXERCISES_MODELNAMES_H
