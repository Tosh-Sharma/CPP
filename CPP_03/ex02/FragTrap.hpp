#ifndef FragTrap_H
#define FragTrap_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	highFivesGuys(void);
};

#endif