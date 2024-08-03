#pragma once

#include <iostream>

class Data {
	private:
		int id;
		std::string name;

	public:
		Data();
		~Data();
		Data(int id, std::string name);
		Data(Data const &other);
		Data &operator=(Data const &other);

		int	getId() const { return this->id; }
		std::string getName() const { return this->name; }
};
