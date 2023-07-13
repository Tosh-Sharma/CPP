#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) {}

std::string	Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::~Weapon() {}