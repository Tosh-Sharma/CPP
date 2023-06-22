#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &type): name(name), type(type) {}

void	HumanA::attack(void) const
{
	cout << name << " attacks with their " << type.getType() << endl;
}

HumanA::~HumanA() {}