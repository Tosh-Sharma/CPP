#ifndef HUMAN_B_H
#define	HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*	type;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& type);
		void	attack(void) const;
		~HumanB();
};

#endif