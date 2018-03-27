//
// Created by torzmich on 20.03.18.
//

#include "Name.h"

namespace modelnames{

    Name::Name(std::string firstName, std::string surname) : firstName(firstName), surname(surname) {}

    const std::string &Name::getFirstName() const {
        return firstName;
    }

    const std::string &Name::getSurname() const {
        return surname;
    }

    const std::string &Name::getSecondName() const {
        return  secondName;
    }

    const std::string &Name::getThirdName() const {
        return thirdName;
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

        if(spaces == 3) {
            int space = name.find(' ');
            firstName = name.substr(0,space);
            name = name.substr(space+1);
            space = name.find(' ');
            secondName = name.substr(0,space);
            name = name.substr(space+1);
            space = name.find(' ');
            thirdName = name.substr(0,space);
            surname = name.substr(space+1);
        }
    }

    void Name::setSecondName(const std::string &secondName) {
        Name::secondName = secondName;
    }

    void Name::setThirdName(const std::string &thirdName) {
        Name::thirdName = thirdName;
    }

    std::string Name::ToFullInitials() {
        std::string initials;
        if(Name::getSecondName() == "")
            initials = Name::getFirstName().substr(0,1) + "." + Name::getSurname().substr(0,1) + ".";
        else if(Name::getThirdName() == "" && Name::getSecondName()!= "")
            initials = Name::getFirstName().substr(0,1) + "." + Name::getSecondName().substr(0,1) + "." + Name::getSurname().substr(0,1) + ".";
        else initials = Name::getFirstName().substr(0,1) + "." + Name::getSecondName().substr(0,1) + "." + Name::getThirdName().substr(0,1) + "." + Name::getSurname().substr(0,1) + ".";

        return initials;
    }

    std::string Name::ToFirstNamesInitials() {
        std::string initials;
        if(Name::getSecondName() == "")
            initials = Name::getFirstName().substr(0,1) + "." + Name::getSurname();
        else if(Name::getThirdName() == "" && Name::getSecondName()!= "")
            initials = Name::getFirstName().substr(0,1) + "." + Name::getSecondName().substr(0,1) + "." + Name::getSurname();
        else initials = Name::getFirstName().substr(0,1) + "." + Name::getSecondName().substr(0,1) + "." + Name::getThirdName().substr(0,1) + "." + Name::getSurname();

        return initials;
    }

    std::string Name::ToSurnameNames() {
        if(Name::getSecondName() == "")
            return Name::getSurname() + " " + Name::getFirstName();
        else if(Name::getThirdName() == "" && Name::getSecondName()!= "")
            return  Name::getSurname() + " " + Name::getFirstName() + " " + Name::getSecondName();
        else return Name::getSurname() + " " + Name::getFirstName() + " " + Name::getSecondName() + " " + Name::getThirdName();

    }

    std::string Name::ToNamesSurname() {
        if(Name::getSecondName() == "")
            return Name::getFirstName() + " " + Name::getSurname();
        else if(Name::getThirdName() == "" && Name::getSecondName()!= "")
            return  Name::getFirstName() + " " + Name::getSecondName() + " " + Name::getSurname();
        else return Name::getFirstName() + " " + Name::getSecondName() + " " + Name::getThirdName() + " " + Name::getSurname();
    }

    bool Name::IsBeforeBySurname(std::string surname) {
        const char* baseLetter = Name::getSurname().c_str();
        const char* givenLetter = surname.c_str();
        int i = 0;
        while(surname[i]!= '\0') {
            if(baseLetter[i] > givenLetter[i]) {
                return true;
            } else if (baseLetter[i] < givenLetter[i]) {
                return false;
            } else {
                i++;
            }
        }

        return false;

    }

    bool Name::IsBeforeByFirstName(std::string firstname) {
        const char* baseLetter = Name::getFirstName().c_str();
        const char* givenLetter = firstname.c_str();
        int i = 0;
        while(surname[i]!= '\0') {
            if(baseLetter[i] > givenLetter[i]) {
                return true;
            } else if (baseLetter[i] < givenLetter[i]) {
                return false;
            } else {
                i++;
            }
        }

        return false;

    }



}

