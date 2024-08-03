#include "Data.hpp"

static uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

static Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}


int main() {
    Data data = Data(42, "Forty-Two");

    uintptr_t raw = serialize(&data);
    std::cout << "Serialized data is " << raw << std::endl;

    Data* deserializedPtr = deserialize(raw);
	std::cout << "Values inside the data objects " << std::endl;
	std::cout << "Data 1: " << data.getId() << ", " << data.getName() << std::endl;
	std::cout << "Data 2: " << deserializedPtr->getId() << ", " << deserializedPtr->getName() << std::endl;

	std::cout << "Addresses of the data objects " << std::endl;
	std::cout << "Data for address 1" << &data << std::endl;
	std::cout << "Data for address 2" << deserializedPtr << std::endl;

    return 0;
}