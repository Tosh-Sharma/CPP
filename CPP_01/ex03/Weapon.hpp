#ifndef	WEAPON_H
#define	WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		void	setType(std::string type);
		std::string	getType() const;
		~Weapon();
};

#endif