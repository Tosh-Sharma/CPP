#ifndef ClapTrap_H
#define ClapTrap_H

#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int		hitPoints;
		int		energyPoints;
		int		attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void);
};

#endif