#include <iostream>
#include <cstdint>
#include "Serializer.hpp"

Serializer::Serializer() : name("Forty-Two"), id(42) {}

Serializer::Serializer(int id, std::string name) : name(name), id(id) {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &other) {
    *this = other;
}

Serializer &Serializer::operator=(Serializer const &other) {
    id = other.id;
    name = other.name;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
