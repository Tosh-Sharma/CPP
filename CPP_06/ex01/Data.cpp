#include <iostream>
#include <cstdint>
#include "Data.hpp"

Data::Data() : id(42), name("Forty-Two") {}

Data::Data(int id, std::string name) : id(id), name(name) {}

Data::~Data() {}

Data::Data(Data const &other) {
    *this = other;
}

Data &Data::operator=(Data const &other) {
    id = other.id;
    name = other.name;
    return *this;
}