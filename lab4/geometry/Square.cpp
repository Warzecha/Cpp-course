//
// Created by damian on 09.04.18.
//

#include <vector>
#include <unordered_set>
#include "Square.h"



namespace geometry
{




    Square::Square(const Point p1, const Point p2, const Point p3, const Point p4) {

//        this->p1 = p1;
//        this->p2 = p2;
//        this->p3 = p3;
//        this->p4 = p4;

        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);

    }

    double Square::Circumference() const {
        if(!checkIfSquare())
            return 0;

        double distance_a = points[0].Distance(points[1]);
        double distance_b = points[0].Distance(points[2]);

        double side = std::min(distance_a, distance_b);

        return 4*side;
    }

    double Square::Area() const {
        if(!checkIfSquare())
            return 0;
        double distance_a = points[0].Distance(points[1]);
        double distance_b = points[0].Distance(points[2]);

        double side = std::min(distance_a, distance_b);

        return side*side;
    }

    bool Square::checkIfSquare() const {

//        double AB = p1.Distance(p2);
//        double AC = p1.Distance(p3);
//        double AD = p1.Distance(p4);
//
//        double diagonal = std::max(AB, AC);
//        diagonal = std::max(diagonal, AD);
//
//        if(diagonal == AB)
//        {
//            if(AC != AD)
//            {
//                return false;
//            }
//
//            double BC = p2.Distance(p3);
//            double BD = p2.Distance(p4);
//
//            if(BC == BD != AC)
//            {
//                return false;
//            }
//
//
//        } else if(diagonal == AC)
//        {
//            if(AB != AD)
//            {
//                return false;
//            }
//
//            double CB = p3.Distance(p2);
//            double CD = p3.Distance(p4);
//
//            if(CB == CD != AB)
//            {
//                return false;
//            }
//
//
//        }else if(diagonal == AD)
//        {
//            if(AB != AC)
//            {
//                return false;
//            }
//
//
//            double DB = p4.Distance(p2);
//            double DC = p4.Distance(p3);
//
//            if(DB == DC != AB)
//            {
//                return false;
//            }
//
//
//
//        }

        std::vector<double> distances;

        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 4; ++j) {

                double distance = points[i].Distance(points[j]);
                distances.push_back(distance);
            }
        }

        std::unordered_set<double > unique_dist;

        for (auto d : distances) {
            unique_dist.insert(d);
        }


        return unique_dist.size() == 2;
    }


}