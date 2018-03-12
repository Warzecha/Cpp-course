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




int GreatestProduct(const std::vector<int> &numbers, int k) {

    std::vector<int> positive;
    std::vector<int> negative;

    for( auto x : numbers)
    {
        if( x > 0)
        {
            addNumber(positive,x);
        } else
        {
            addNumber(negative,x);
        }
    }

    std::vector<int> greatest;

    if((negative.size()/2*2) + positive.size() > k)
    {
        greatest = positive;


        for (int j = 0;  j < int(negative.size())-1 && (j < k - 1); j+=2)
        {


            if(greatest.size() < k - 1 )
            {
                addNumber(greatest, -negative[j]);
                addNumber(greatest, -negative[j+1]);
            }else if((-negative[j])*(-negative[j+1]) > positive[k-1]*positive[k-2])
            {
                addNumber(greatest, -negative[j]);
                addNumber(greatest, -negative[j+1]);
            }

        }




    }
    else
    {






    }



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
    int product = greatest[0];
    for( auto it = greatest.begin()+1; it != greatest.begin() + k; it++)
    {
        product *= *it;

    }



    return product;
}
