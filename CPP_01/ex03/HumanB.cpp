#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), type(NULL) {}

void	HumanB::setWeapon(Weapon& type)
{
	this->type = &type;
}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their "
			<< type->getType() << std::endl;
}

HumanB::~HumanB() {}