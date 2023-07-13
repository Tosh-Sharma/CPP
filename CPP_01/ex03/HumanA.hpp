#ifndef HUMAN_A_H
#define	HUMAN_A_H

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon	&type;
	public:
		HumanA(std::string name, Weapon &type);
		void	attack(void) const;
		~HumanA();
};

#endif