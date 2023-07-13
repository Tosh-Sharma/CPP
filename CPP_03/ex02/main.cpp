#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("trappy");

	fragTrap.attack("mappy");
	fragTrap.takeDamage(5);
	fragTrap.attack("mappy");
	fragTrap.takeDamage(5);
	fragTrap.takeDamage(3);
	fragTrap.attack("mappy");
	fragTrap.highFivesGuys();
	fragTrap.beRepaired(3);
}