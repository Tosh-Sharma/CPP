#ifndef HUMAN_B_H
#define	HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
	private:
		string	name;
		Weapon*	type;
	public:
		HumanB(string name);
		void	setWeapon(Weapon* type);
		void	attack(void) const;
		~HumanB();
};

#endif