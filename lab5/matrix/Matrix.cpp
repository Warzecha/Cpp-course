//
// Created by damian on 27.03.18.
//

#include <iostream>
#include "Matrix.h"


namespace algebra
{
    Matrix::Matrix(unsigned long _rows, unsigned long _cols) {

        rows = _rows;
        cols = _cols;

        array = new std::complex<double>* [rows];

        for (int i = 0; i < rows; ++i) {
            array[i] = new std::complex<double> [cols];

        }
    }



    std::pair<size_t, size_t> Matrix::Size() const {
        return std::pair<size_t, size_t>(rows,cols);
    }

//    Matrix::Matrix(std::initializer_list<std::initializer_list<std::complex<double>>> initializer_list) {
////        rows = (int)(initializer_list.begin()).size();
////        cols = (int)listlist.size();
//        rows = initializer_list.size();
//        cols = initializer_list.begin()->size();
//
//        array = new std::complex<double>* [rows];
//
//        for (int i = 0; i < rows; ++i) {
//            array[i] = new std::complex<double> [cols];
//            for (int j = 0; j < cols; j++) {
//                array[i][j] = *((*(initializer_list.begin()+i)).begin()+j);
//            }
//
//        }
//
//
//    }

    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> initializer_list) {
        rows = initializer_list.size();
        cols = initializer_list.begin()->size();

        array = new std::complex<double>* [rows];

        for (int i = 0; i < rows; ++i) {
            array[i] = new std::complex<double> [cols];
            for (int j = 0; j < cols; j++) {
                array[i][j] = *((*(initializer_list.begin()+i)).begin()+j);
            }

        }

    }

    std::string Matrix::Print() const {
        if(rows == 0 || cols == 0)
            return "[]";


        std::string tmp = "[";

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < cols; ++j) {

                std::string real = std::to_string(array[i][j].real());
                std::string imag = std::to_string(array[i][j].imag());


                real.erase ( real.find_last_not_of('0') + 1, std::string::npos );
                imag.erase ( imag.find_last_not_of('0') + 1, std::string::npos );

                if(*(real.end()-1) == '.')
                    real.erase(real.length()-1,1);

                if(*(imag.end()-1) == '.')
                    imag.erase(imag.length()-1,1);

                tmp +=  real + "i" + imag +", ";
            }

            tmp.erase(tmp.length()-2,2);
            tmp += "; ";

        }


        tmp.erase(tmp.length()-2,2);
        tmp += "]";

        return tmp;
    }

    Matrix Matrix::Add(const Matrix &other) const{

        if(other.Size() != this->Size())
        {
            //rzuc wyjatkiem jak sie nauczysz

        }else
        {

            Matrix tmp(other);

            for (int i = 0; i < tmp.rows; ++i) {
                for (int j = 0; j < tmp.cols; ++j) {
                    tmp.array[i][j] += array[i][j];
                }
            }

            return tmp;

        }



    }

    Matrix::Matrix(const Matrix &other) {

        rows = other.rows;
        cols = other.cols;

        array = new std::complex<double>* [rows];

        for (int i = 0; i < rows; ++i) {
            array[i] = new std::complex<double> [cols];
            for (int j = 0; j < cols; j++) {
                array[i][j] = other.array[i][j];
            }

        }


    }


    Matrix::Matrix(Matrix &&other) : rows(other.rows), cols(other.cols), array(other.array)
    {
        other.cols = 0;
        other.rows = 0;
        other.array = nullptr;
    }



    Matrix Matrix::Sub(const Matrix &other) const {
        if(other.Size() != this->Size())
        {
            //rzuc wyjatkiem jak sie nauczysz

        }else
        {

            Matrix tmp(*this);

            for (int i = 0; i < tmp.rows; ++i) {
                for (int j = 0; j < tmp.cols; ++j) {
                    tmp.array[i][j] -= other.array[i][j];
                }
            }

            return tmp;

        }
    }

    Matrix Matrix::Mul(const Matrix &other) const {
        if( other.rows != cols)
        {
            return Matrix(0,0);
            //rzuc wyjatkiem jak sie nauczysz

        }else
        {

            Matrix tmp(rows,other.cols);

            for (int i = 0; i < tmp.rows; ++i) {
                for (int j = 0; j < tmp.cols; ++j) {
                    for (int k = 0; k < cols; ++k) {

                        tmp.array[i][j] += (array[i][k] * other.array[k][j]);

                    }
                }
            }

            return tmp;

        }
    }

    Matrix Matrix::Pow(int pow) const {
        Matrix tmp(*this);
        if(pow == 0)
        {
            for (int i = 0; i < tmp.rows; ++i) {
                for (int j = 0; j < tmp.cols; ++j) {
                    if(i == j)
                        tmp.array[i][j] = 1;
                    else
                        tmp.array[i][j] = 0;
                }

            }

            return tmp;

        }



        for (int i = 1; i < pow; ++i) {
            tmp = tmp.Mul(*this);
        }

        return tmp;
    }

    Matrix::~Matrix() {

        for (int i = 0; i < rows; ++i) {

            delete[] array[i];

        }
        delete[] array;

    }

    Matrix &Matrix::operator=(Matrix &&other) {

        if(this != &other)
        {
            for (int i = 0; i < rows; ++i) {
                delete[]array[i];
            }
            delete[](array);

            this->array = other.array;
            this->rows = other.rows;
            this->cols = other.cols;

            other.array = nullptr;
            other.rows = 0;
            other.cols = 0;

        }
        return *this;
    }


}


