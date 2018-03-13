//
// Created by damian on 12.03.18.
//

#include "GreatestProduct.h"
#include <algorithm>
#include <iostream>


void addNumber(std::vector<int> &numbers, int x)
{
    if (numbers.size() == 0)
        numbers.push_back(x);

    else
    {
        int i;

        for (i = 0; numbers[i] > x && i < numbers.size()  ; ++i) {

        }

        numbers.insert(numbers.begin() + i, x);
    }


}

int function (std::vector<int> numbers, int index, int k, int step)
{
    if(step == k )
        return 1;
    if(index == numbers.size())
        return 0;

    int a = function(numbers, index+1, k, step);
    int b = 0;

    //if(index != numbers.size()-1)
    b = numbers[index] * function(numbers, index+1, k, step+1);

    if(a == 0)
        return b;
    else if(b == 0)
        return a;
    else return std::max(a, b);

//


}


int GreatestProduct(const std::vector<int> &numbers, int k) {



    int product;
    product = function(numbers, 0, k, 0);
    return product;





















//    std::vector<int> positive;
//    std::vector<int> negative;
//
//    for( auto x : numbers)
//    {
//        if( x > 0)
//        {
//            addNumber(positive,x);
//        } else
//        {
//            addNumber(negative,x);
//        }
//    }
//
//    std::vector<int> greatest;
//
//    if((negative.size()/2*2) + positive.size() > k)
//    {
//        greatest = positive;
//
//
//        for (int j = 0;  j < int(negative.size())-1 && (j < k - 1); j+=2)
//        {
//
//
//            if(greatest.size() < k - 1 )
//            {
//                addNumber(greatest, -negative[j]);
//                addNumber(greatest, -negative[j+1]);
//            }else if((-negative[j])*(-negative[j+1]) > positive[k-1]*positive[k-2])
//            {
//                addNumber(greatest, -negative[j]);
//                addNumber(greatest, -negative[j+1]);
//            }
//
//        }
//
//
//
//
//    }
//    else
//    {
//
//
//
//
//
//
//    }



    //int n = std::min(int(negative.size()), k);
    //std::cout<<negative.size()<<std::endl;

//    if( (negative.size()/2*2) + positive.size() >= k)
//    {
//
//    }
//
//    for (int j = 0;  j < int(negative.size())-1 && (j < k - 1); j+=2)
//    {
//
//
//        if(positive.size() < k - 1 )
//        {
//            addNumber(positive, negative[j], k);
//            addNumber(positive, negative[j+1], k);
//        }else if(negative[j]*negative[j+1] > positive[k-1]*positive[k-2])
//        {
//            addNumber(positive, negative[j], k);
//            addNumber(positive, negative[j+1], k);
//
//        }
//
//    }
//
//
//
//



//    int product = greatest[0];
//    for( auto it = greatest.begin()+1; it != greatest.begin() + k; it++)
//    {
//        product *= *it;
//
//    }



    return product;
}
