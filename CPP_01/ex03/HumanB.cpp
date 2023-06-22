#include "HumanB.hpp"

HumanB::HumanB(string name): name(name) {}

void	HumanB::setWeapon(Weapon* type)
{
	this->type = type;
}

void	HumanB::attack(void) const
{
	cout << name << " attacks with their " << type->getType() << endl;
}

HumanB::~HumanB() {}