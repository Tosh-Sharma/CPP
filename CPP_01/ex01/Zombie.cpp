#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name): name(name) {}

void	Zombie::announce(void) const
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::~Zombie()
{
	std::cout << name << " : has been destroyed" << std::endl;
}

void	Zombie::set_zombie_name(std::string uname)
{
	this->name = uname;
}