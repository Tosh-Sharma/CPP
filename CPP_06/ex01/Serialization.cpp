#include <iostream>
#include <cstdint>

struct Data {
    int id;
    std::string name;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

int main() {
    Data myData = {1, "Test"};
    Data* ptr = &myData;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized: " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << deserializedPtr->id << ", " << deserializedPtr->name << std::endl;

    return 0;
}