#include "Serializer.hpp"


int main() {
	Data pointer;
	pointer.name = "I AM BATMAN";
	pointer.id = 42;

	std::cout << "OG Pointer address is: " << &pointer << std::endl;
	std::cout << "Name is " << pointer.name << ", id is " << pointer.id << std::endl;

	Serializer serializer;
	uintptr_t raw_pointer = serializer.serialize(&pointer);
	Data *original_pointer = serializer.deserialize(raw_pointer);

	std::cout << "Re-Pointer address is : " << original_pointer << std::endl;
	std::cout << "Name is " << original_pointer->name << ", id is " << original_pointer->id << std::endl;
	std::cout << "Pointer address is: " << &pointer << std::endl;
	std::cout << "Name is " << pointer.name << ", id is  " << pointer.id << std::endl;
	std::cout << "Pointer address should be equal to Re-Pointer address." << std::endl;

	std::cout << "Raw pointer is: " << &raw_pointer << std::endl;
	std::cout << "Raw pointer should not be equal to original pointer." << std::endl;

    return 0;
}