#pragma once

#include <iostream>
#include <stdint.h>

typedef struct data_struct {
	std::string name;
	int 		id;
}	Data;

class Serializer {
	private:
		std::string name;
		int			id;

	public:
		Serializer();
		~Serializer();
		Serializer(int id, std::string name);
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);

		int			getId() const { return this->id; }
		std::string	getName() const { return this->name; }

		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};
