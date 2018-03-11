//
// Created by damian on 05.03.18.
//

#include "Palindrome.h"
#include "./../reversestring/ReverseString.h"


bool is_palindrome(std::string str)
{
    if (str == std::string(str.rbegin(), str.rend())) {
        return true;
    }
    else return false;
}
