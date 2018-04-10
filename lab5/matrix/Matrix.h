//
// Created by damian on 27.03.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H


#include <complex>
#include <vector>

namespace algebra{
    class Matrix {
    public:

        Matrix(unsigned long rows, unsigned long cols);

        //Matrix(std::initializer_list<std::initializer_list<std::complex<double>>> initializer_list);
        Matrix(std::initializer_list<std::vector<std::complex<double>>>);

        Matrix(const Matrix &other);
        Matrix(Matrix &&other);

        Matrix &operator= (Matrix &&other);


        std::pair<size_t, size_t> Size() const ;

        std::string Print() const ;

        Matrix Add(const Matrix& other) const ;
        Matrix Sub(const Matrix& other) const ;
        Matrix Mul(const Matrix& other) const ;
        Matrix Pow(int pow)const ;

        virtual ~Matrix();


    private:

        std::complex<double> ** array;
        unsigned long rows;
        unsigned long cols;

    };

}




#endif //JIMP_EXERCISES_MATRIX_H
