//
// Created by torzmich on 20.03.18.
//

#include "ModelNames.h"

Name::Name(std::string firstName, std::string surname) : firstName(firstName), surname(surname) {}

const std::string &Name::getFirstName() const {
    return firstName;
}

const std::string &Name::getSurname() const {
    return surname;
}

const std::experimental::optional<std::string> &Name::getSecondName() const {
    return std::experimental::make_optional(secondName);
}

const std::experimental::optional<std::string> &Name::getThirdName() const {
    return std::experimental::make_optional(thirdName);
}

void Name::setFirstName(const std::string &firstName) {
    Name::firstName = firstName;
}

void Name::setSurname(const std::string &surname) {
    Name::surname = surname;
}

Name::Name(std::string name) {

    int spaces = 0;
    for(int i = 0; name[i]!= '\0'; i++) {
        if(name[i] == ' ')
            spaces++;
    }

    if(spaces == 1) {
        int space = name.find(' ');
        firstName = name.substr(0,space);
        surname = name.substr(space+1);
    }
    if(spaces == 2) {
        int space = name.find(' ');
        firstName = name.substr(0,space);
        name = name.substr(space+1);
        space = name.find(' ');
        secondName = name.substr(0,space);
        surname = name.substr(space+1);

    }
}

void Name::setSecondName(const std::string &secondName) {
    Name::secondName = secondName;
}

void Name::setThirdName(const std::string &thirdName) {
    Name::thirdName = thirdName;
}
