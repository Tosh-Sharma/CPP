#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type): name(name), type(type) {}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " <<
			type.getType() << std::endl;
}

HumanA::~HumanA() {}