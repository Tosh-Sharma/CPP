#ifndef	WEAPON_H
#define	WEAPON_H

#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

class Weapon
{
	private:
		string	type;

	public:
		Weapon(string type);
		void	setType(string type);
		string	getType() const;
		~Weapon();
};

#endif