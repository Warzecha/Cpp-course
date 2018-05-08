//
// Created by damian on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <memory>

namespace academia
{
    class Serializer {
    public:
//        virtual Serializer(std::ostream &_ostream);
        Serializer(std::ostream *_ostream);

        virtual void use_serializer() = 0;



    private:
        std::ostream &ostream;
    };


    class JsonSerializer : public Serializer
    {
    public:
        using Serializer::Serializer

        virtual void use_serializer() override ;


    };








    class Serializable
    {
        virtual void Serialize(Serializer *serializer) = 0;

    };



    class Room : public Serializable
    {
    public:
        enum class Type { COMPUTER_LAB, LECTURE_HALL, CLASSROOM};
        Room(int id, const std::string &name, Type type);
        void Serialize(Serializer *serializer) override ;


    private:

        int id;
        std::string name;



        Type type;


    };


    class Building : public Serializable
    {


    public:
        Building(int id, const std::string &name, const std::vector<Room> &rooms);


        void Serialize(Serializer *serializer) override ;

    private:
        int id;
        std::string name;
        std::vector<Room> rooms;

    };






}



#endif //JIMP_EXERCISES_SERIALIZATION_H
