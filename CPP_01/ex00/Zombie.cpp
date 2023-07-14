#include "Zombie.hpp"

Zombie::Zombie(): name("default")
{
	std::cout << "Default constructor called making the Zombies name." << std::endl;
}

Zombie::Zombie(std::string name): name(name) {}

void	Zombie::announce(void) const
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::~Zombie()
{
	std::cout << name << " : has been destroyed" << std::endl;
}