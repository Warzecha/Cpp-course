//
// Created by damian on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


#include <experimental/optional>
#include <string>
#include <vector>
#include <memory>


namespace academia
{
    class Serializable;

    class Serializer {
    public:
//        virtual Serializer(std::ostream &_ostream);
        Serializer(std::ostream *_ostream);

//        virtual void use_serializer() = 0;

        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;
        virtual void Separator();

    protected:
        std::ostream &ostream;
    };


    class JsonSerializer : public Serializer
    {
    public:
        using Serializer::Serializer;

//        virtual void use_serializer() override ;
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

        void Separator() override;


    };

    class XmlSerializer : public Serializer
    {
    public:
        using Serializer::Serializer;

//        virtual void use_serializer() override ;
        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;









    };








    class Serializable
    {
    public:
        virtual void Serialize(Serializer *serializer) const = 0;

    };



    class Room : public Serializable
    {
    public:
        enum class Type { COMPUTER_LAB, LECTURE_HALL, CLASSROOM };
        const char* ToString(Type v) const;

        Room(int id, const std::string &name, Type type);
        void Serialize(Serializer *serializer) const override ;


    private:

        int id;
        std::string name;



        Type type;


    };


    class Building : public Serializable
    {


    public:
        Building(int id, const std::string &name, const std::vector<Room> &rooms);


        void Serialize(Serializer *serializer) const override ;

        int Id() const;

    private:
        int id;
        std::string name;
        std::vector<Room> rooms;

    };





    class BuildingRepository
    {
    public:
        BuildingRepository(const std::vector<Building> &buildings);

        BuildingRepository();

        BuildingRepository(const std::initializer_list<Building> &buildings);

        void Add(const Building &new_building);
        void StoreAll(Serializer *serializer);

        std::experimental::optional<Building> operator[] (int _id) const ;

    private:
        std::vector<Building> buildings;
    };





}



#endif //JIMP_EXERCISES_SERIALIZATION_H
