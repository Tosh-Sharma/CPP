#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
/**
 * In the below code, there shall be no leaks until
 * line 9-10 containing the heap_zombie declaration
 * and announce function call is commented out.
*/
int	main(void)
{
	Zombie *heap_zombie_main = newZombie("HEAPER");

	randomChump("STACKER");
	// Comment below line to test for leaks.
	// system("leaks output");
	return (0);
}