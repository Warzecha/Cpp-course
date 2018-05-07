//
// Created by damian on 29.04.18.
//

#include <cstring>
#include "Pesel.h"

namespace academia
{









    Pesel::Pesel(const std::string &pesel) {
        validatePESEL( pesel.c_str());

        this->pesel = pesel;

    }

    bool Pesel::validatePESEL(const char *_pesel) {

        if(std::strlen(_pesel) != 11)
        {
            throw InvalidPeselLength("InvalidPeselLength");
        }

        for (int i = 0; i < std::strlen(_pesel); ++i) {

            if(_pesel[i] < '0' || _pesel[i] > '9')
                throw InvalidPeselCharacter(_pesel);

        }

        int sum = 9 * (_pesel[0] - '0') + 7 * (_pesel[1] - '0') + 3 * (_pesel[2] - '0') + (_pesel[3] - '0') + 9 * (_pesel[4] - '0') + 7 * (_pesel[5] - '0') + 3 * (_pesel[6] - '0') + (_pesel[7] - '0') + 9 * (_pesel[8] - '0') + 7 * (_pesel[9] - '0');
        if(sum % 10 != (_pesel[10]-'0'))
        {
            throw InvalidPeselChecksum("InvalidPeselChecksum");
        }
        return true;
    }

    AcademiaDataValidationError::AcademiaDataValidationError(const std::string &__arg) : logic_error(__arg) {}



    InvalidPeselLength::InvalidPeselLength(const std::string &__arg, int length) : AcademiaDataValidationError("Invalid PESEL(" + __arg + ") length: " + std::to_string(length)){

    }

    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &__arg, int checksum) : AcademiaDataValidationError("Invalid PESEL(" + __arg + ") checksum: " + std::to_string(checksum)) {

    }

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &__arg) : AcademiaDataValidationError("Invalid PESEL(" + __arg + ") character set") {}
}