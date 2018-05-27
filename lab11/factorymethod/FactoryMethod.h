//
// Created by damian on 27.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H


#include <string>
#include <memory>

namespace factoryMethod
{

    template<class T>
    auto Create()
    {
        auto t = std::make_unique<T>();
        return *t.get();

    }










    class MyType {
    public:
        MyType();

        std::string SayHello() const ;


    };


}




#endif //JIMP_EXERCISES_FACTORYMETHOD_H
