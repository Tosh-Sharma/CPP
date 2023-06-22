#include "HumanB.hpp"

HumanB::HumanB(string name): name(name), type(NULL) {}

void	HumanB::setWeapon(Weapon& type)
{
	this->type = &type;
}

void	HumanB::attack(void) const
{
	cout << name << " attacks with their " << type->getType() << endl;
}

HumanB::~HumanB() {}