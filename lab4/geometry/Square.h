//
// Created by damian on 09.04.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"

namespace geometry
{

    class Square {
    public:
        Square(Point p1, Point p2, Point p3, Point p4);

        double Circumference() const ;

        double Area() const ;
        bool checkIfSquare() const ;


    private:
        std::vector<Point> points;


    };


}



#endif //JIMP_EXERCISES_SQUARE_H
