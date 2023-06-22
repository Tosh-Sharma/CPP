#include "Zombie.hpp"

void	randomChump(string name)
{
	// If this is commented out, it causes
	// leaks due to us losing reference of the
	// heap_zombie outside the scope of randomChump.
	// Zombie *heap_zombie = newZombie("HEAPER");
	// heap_zombie->announce();

	Zombie chump = Zombie(name);

	chump.announce();
	// delete heap_zombie;
}