#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("trappy");

	scavTrap.attack("mappy");
	scavTrap.takeDamage(5);
	scavTrap.attack("mappy");
	scavTrap.takeDamage(5);
	scavTrap.takeDamage(3);
	scavTrap.attack("mappy");
	scavTrap.guardGate();
	scavTrap.beRepaired(3);
}