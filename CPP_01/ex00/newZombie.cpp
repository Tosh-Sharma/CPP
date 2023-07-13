#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *chump = new Zombie(name);
	return chump;
}