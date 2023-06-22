#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Zombie
{
	private:
		string	name;
	public:
		Zombie();
		Zombie(string name);
		~Zombie();
		void	announce(void) const;
};

#endif