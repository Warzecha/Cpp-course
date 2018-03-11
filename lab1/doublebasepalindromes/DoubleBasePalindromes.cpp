//
// Created by damian on 05.03.18.
//

#include "DoubleBasePalindromes.h"
#include "../palindrome/Palindrome.h"


std::string dec2bin(int dec)
{

    std::string str;
    while(dec!=0) {str=(dec%2==0 ?"0":"1")+str; dec/=2;}
    return str;
}



uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t sum = 0;

    for (int i = 1; i < max_vaule_exculsive ; ++i) {

        if(is_palindrome(std::to_string(i)) && is_palindrome(dec2bin(i)))
        {
            sum += i;
        }
    }
    return sum;
}