#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(string name): name(name) {}

void	Zombie::announce(void) const
{
	cout << name << " : BraiiiiiiinnnzzzZ..." << endl; 
}

Zombie::~Zombie()
{
	cout << name << " : has been destroyed" << endl;
}

void	Zombie::set_zombie_name(string uname)
{
	this->name = uname;
}