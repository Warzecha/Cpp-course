//
// Created by torzmich on 20.03.18.
//
#include "Name.h"
#include <memory>


int main() {

    std::unique_ptr<Name> name = std::make_unique<Name>("Jan","Kowalski");
    std::unique_ptr<Name> name2 = std::make_unique<Name>("Dominik Domin Dolek Nowak");

    std::cout<<name->ToFullInitials()<<std::endl;
    std::cout<<name2->ToFullInitials()<<std::endl;

    std::cout<<name->ToFirstNamesInitials()<<std::endl;
    std::cout<<name2->ToFirstNamesInitials()<<std::endl;

    std::cout<<name->ToSurnameNames()<<std::endl;
    std::cout<<name2->ToSurnameNames()<<std::endl;

    std::cout<<name->ToNamesSurname()<<std::endl;
    std::cout<<name2->ToNamesSurname()<<std::endl;

    std::string surname = "Nowak";
    std::string firstName = "Pitter";

    if(name->IsBeforeBySurname(surname))
        std::cout<<surname<<" jest wyzej w alfabecie niz "<<name->getSurname()<<std::endl;
    else std::cout<<surname<<" jest nizej w alfabecie niz "<<name->getSurname()<<std::endl;

    if(name2->IsBeforeByFirstName(firstName))
        std::cout<<firstName<<" jest wyzej w alfabecie niz "<<name2->getFirstName();
    else std::cout<<firstName<<" jest nizej w alfabecie niz "<<name2->getFirstName();

    return 0;
}