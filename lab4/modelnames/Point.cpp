//
// Created by damian on 26.03.18.
//

#include <cmath>
#include <ostream>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
Point::Point():x_(0),y_(0){
    std::cout << "Konstruktor bezparametrowy" << endl;
}

Point::Point(double x, double y){
    std::cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    std::cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    std::cout << std::endl;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return this->x_;
}

double Point::GetY() const {
    return this->y_;
}

void Point::SetX(double x) {
    this->x_ = x;
}

void Point::SetY(double y) {
    this->y_ = y;
}
