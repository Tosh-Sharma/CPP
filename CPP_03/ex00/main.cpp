#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("trappy");

	claptrap.attack("mappy");
	claptrap.takeDamage(5);
	claptrap.attack("mappy");
	claptrap.takeDamage(5);
	claptrap.takeDamage(3);
	claptrap.attack("mappy");
	claptrap.beRepaired(3);
	claptrap.takeDamage(3);
}