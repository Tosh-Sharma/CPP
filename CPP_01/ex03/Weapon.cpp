#include "Weapon.hpp"

Weapon::Weapon(string type): type(type) {}

string	Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(string type)
{
	this->type = type;
}

Weapon::~Weapon() {}