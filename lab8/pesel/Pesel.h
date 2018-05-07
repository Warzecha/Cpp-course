//
// Created by damian on 29.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <exception>
#include <stdexcept>

namespace academia
{
    class Pesel {
    public:
        Pesel(const std::string &pesel);


        static bool validatePESEL(const char* _pesel);
    private:


        std::string pesel;
    };



    class AcademiaDataValidationError : public std::logic_error
    {
    public:
        AcademiaDataValidationError(const std::string &__arg);

    public:




    };

    class InvalidPeselLength : public AcademiaDataValidationError
    {
    public:
        InvalidPeselLength(const std::string &__arg, int checksum);


        using AcademiaDataValidationError::AcademiaDataValidationError;
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError
    {
    public:
        InvalidPeselChecksum(const std::string &__arg, int checksum);
        using AcademiaDataValidationError::AcademiaDataValidationError;
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError
    {
    public:
        InvalidPeselCharacter(const std::string &__arg);

//    public:
//        using AcademiaDataValidationError::AcademiaDataValidationError;
    };





}




#endif //JIMP_EXERCISES_PESEL_H
