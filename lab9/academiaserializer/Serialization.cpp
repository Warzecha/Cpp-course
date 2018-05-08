//
// Created by damian on 08.05.18.
//

#include "Serialization.h"


namespace academia
{


    Room::Room(int id, const std::string &name, Room::Type type) : id(id), name(name), type(type) {}

    Building::Building(int id, const std::string &name, const std::vector<Room> &rooms) : id(id), name(name),
                                                                                          rooms(rooms) {}


    Serializer::Serializer(std::ostream *_ostream) : ostream(*_ostream){


    }
}