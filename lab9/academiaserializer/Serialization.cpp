//
// Created by damian on 08.05.18.
//

#include <sstream>
#include "Serialization.h"


namespace academia
{


    Room::Room(int id, const std::string &name, Room::Type type) : id(id), name(name), type(type) {}

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");

        serializer->IntegerField("id", id);
        serializer->Separator();
        serializer->StringField("name", name);
        serializer->Separator();
        serializer->StringField("type", ToString(type));
        serializer->Footer("room");

    }

    const char *Room::ToString(Room::Type v) const {

        switch (v)
        {
            case Type::COMPUTER_LAB:   return "COMPUTER_LAB";
            case Type::LECTURE_HALL:   return "LECTURE_HALL";
            case Type::CLASSROOM:   return "CLASSROOM";
            default:      return "[Unknown Room_type]";
        }
    }

    Building::Building(int id, const std::string &name, const std::vector<Room> &rooms) : id(id), name(name),
                                                                                          rooms(rooms) {}

    void Building::Serialize(Serializer *serializer) const {

        serializer->Header("building");

        serializer->IntegerField("id", id);
        serializer->Separator();
        serializer->StringField("name", name);
        serializer->Separator();
        std::vector<std::reference_wrapper<const academia::Serializable>> value(rooms.begin(),rooms.end());

        serializer->ArrayField("rooms", value);
        serializer->Footer("room");

    }


    Serializer::Serializer(std::ostream *_ostream) : ostream(*_ostream){


    }

    void Serializer::Separator() {

    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        ostream << "\"" + field_name + "\": " + std::to_string(value);
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        ostream << "\"" + field_name + "\": " + std::to_string(value);
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        ostream << "\"" + field_name + "\": \"" + value + "\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        ostream << "\"" + field_name + "\": " + std::to_string(value);

    }

    void JsonSerializer::Header(const std::string &object_name) {
        ostream << std::string("{");

    }

    void JsonSerializer::Footer(const std::string &object_name) {
        ostream  << std::string("}");
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        ostream << "\"" + field_name + "\": ";
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        ostream << "\"" + field_name + "\": [";



        for(auto it = value.begin(); it != value.end(); ++it)
        {
            it->get().Serialize(this);

            if(std::next(it) != value.end())
            {
                this->Separator();
            }

        }


        ostream << std::string("]");
    }

    void JsonSerializer::Separator() {
        ostream << std::string(", ");

    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {

        ostream << "<" + field_name + ">" + std::to_string(value) +  "<\\" + field_name + ">";

    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        ostream << "<" + field_name + ">" + std::to_string(value) +  "<\\" + field_name + ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        ostream << "<" + field_name + ">" + std::to_string(value) +  "<\\" + field_name + ">";

    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        ostream << "<" + field_name + ">" + value +  "<\\" + field_name + ">";

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    }

    void XmlSerializer::Header(const std::string &object_name) {
        ostream << "<" + object_name + ">";

    }

    void XmlSerializer::Footer(const std::string &object_name) {
        ostream << "<\\" + object_name + ">";
    }

    void XmlSerializer::Separator() {

    }
}