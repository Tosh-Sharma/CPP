#ifndef HUMAN_A_H
#define	HUMAN_A_H

#include "Weapon.hpp"

class HumanA
{
	private:
		string	name;
		Weapon	&type;
	public:
		HumanA(string name, Weapon &type);
		void	attack(void) const;
		~HumanA();
};

#endif