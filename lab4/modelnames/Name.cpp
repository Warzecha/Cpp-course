//
// Created by torzmich on 20.03.18.
//

#include <regex>
#include "Name.h"

namespace model{

    Name::Name(std::string firstName, std::string surname) : firstName(firstName), surname(surname) {

    }



    void Name::setFirstName(const std::string &firstName) {
        Name::firstName = firstName;
    }

    void Name::setSurname(const std::string &surname) {
        Name::surname = surname;
    }

//    Name::Name(std::string name) {
//
//        int spaces = 0;
//        for(int i = 0; name[i]!= '\0'; i++) {
//            if(name[i] == ' ')
//                spaces++;
//        }
//
//        if(spaces == 1) {
//            int space = name.find(' ');
//            firstName = name.substr(0,space);
//            surname = name.substr(space+1);
//        }
//        if(spaces == 2) {
//            int space = name.find(' ');
//            firstName = name.substr(0,space);
//            name = name.substr(space+1);
//            space = name.find(' ');
//            secondName = name.substr(0,space);
//            surname = name.substr(space+1);
//
//        }
//
//        if(spaces == 3) {
//            int space = name.find(' ');
//            firstName = name.substr(0,space);
//            name = name.substr(space+1);
//            space = name.find(' ');
//            secondName = name.substr(0,space);
//            name = name.substr(space+1);
//            space = name.find(' ');
//            thirdName = name.substr(0,space);
//            surname = name.substr(space+1);
//        }
//    }

    void Name::setSecondName(const std::string &secondName) {
        Name::secondName = secondName;
    }

    void Name::setThirdName(const std::string &thirdName) {
        Name::thirdName = thirdName;
    }

    std::string Name::ToFullInitials() {
        std::string initials;
        if(!Name::secondName)
            initials = Name::FirstName().substr(0,1) + ". " + Name::Surname().substr(0,1) + ".";
        else if(!Name::ThirdName() && Name::SecondName())
            initials = Name::FirstName().substr(0,1) + ". " + Name::SecondName().value().substr(0,1) + ". " + Name::Surname().substr(0,1) + ".";
        else initials = Name::FirstName().substr(0,1) + ". " + Name::SecondName().value().substr(0,1) + ". " + Name::ThirdName().value().substr(0,1) + ". " + Name::Surname().substr(0,1) + ".";

        return initials;
    }

    std::string Name::ToFirstNamesInitials() {
        std::string initials;
        if(!Name::SecondName())
            initials = Name::FirstName().substr(0,1) + ". " + Name::Surname();
        else if(!Name::ThirdName() && Name::SecondName())
            initials = Name::FirstName().substr(0,1) + ". " + Name::SecondName().value().substr(0,1) + ". " + Name::Surname();
        else initials = Name::FirstName().substr(0,1) + ". " + Name::SecondName().value().substr(0,1) + ". " + Name::ThirdName().value().substr(0,1) + ". " + Name::Surname();

        return initials;
    }

    std::string Name::ToSurnameNames() {
        if(!Name::SecondName())
            return Name::Surname() + " " + Name::FirstName();
        else if(!Name::ThirdName() && Name::SecondName())
            return  Name::Surname() + " " + Name::FirstName() + " " + Name::SecondName().value();
        else return Name::Surname() + " " + Name::FirstName() + " " + Name::SecondName().value() + " " + Name::ThirdName().value();

    }

    std::string Name::ToNamesSurname() {
        if(!Name::SecondName())
            return Name::FirstName() + " " + Name::Surname();
        else if(!Name::ThirdName() && Name::SecondName())
            return  Name::FirstName() + " " + Name::SecondName().value() + " " + Name::Surname();
        else return Name::FirstName() + " " + Name::SecondName().value() + " " + Name::ThirdName().value() + " " + Name::Surname();
    }

    bool Name::IsBeforeBySurname(Name & name) {
        return (surname.compare(name.surname)) < 0;
    }

    bool Name::IsBeforeByFirstName(Name & name) {
        return (firstName.compare(name.firstName)) < 0;
    }

    std::string Name::FirstName() const {
        return firstName;
    }

    std::experimental::optional<std::string> Name::SecondName() const {
        return secondName;
    }

    std::experimental::optional<std::string> Name::ThirdName() const {
        return thirdName;
    }

    std::string Name::Surname() const {
        return surname;
    }

    Name::Name(std::string name_str) {

        std::regex full_expression("^(\\w+)\\s+(\\w+)\\s+(\\w+)\\s+(\\w+)");
        std::regex second_name_expression("^(\\w+)\\s+(\\w+)\\s+(\\w+)");
        std::regex just_surname_expression("^(\\w+)\\s+(\\w+)");
        std::cmatch m;

        const char * name= name_str.c_str();
        if(std::regex_match(name, m, full_expression))
        {
            firstName = m[1].str();
            secondName = m[2].str();
            thirdName = m[3].str();
            surname = m[4].str();
        }else if(std::regex_match(name, m, second_name_expression))
        {
            firstName = m[1].str();
            secondName = m[2].str();
            surname = m[3].str();
        }else if(std::regex_match(name, m, just_surname_expression))
        {
            firstName = m[1].str();
            surname = m[2].str();
        }



    }


}

