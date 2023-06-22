#include "Zombie.hpp"

Zombie	*newZombie(string name)
{
	Zombie *chump = new Zombie(name);
	return chump;
}