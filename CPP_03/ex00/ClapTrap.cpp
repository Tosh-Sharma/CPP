#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name): name(name)
{
	std::cout << "Constructor called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << this->name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
			<< " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else if (this->hitPoints > 0 && this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " ran out of energy" << std::endl; 
	else if (this->hitPoints <= 0 && this->energyPoints > 0)
		std::cout << "ClapTrap " << this->name << " has run out of Hit Points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= (int)amount;
	std::cout << "Claptrap " << this->name << " took " << amount << " points of damage" << std::endl;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->hitPoints += (int)amount;
		this->energyPoints -= 1;
	}
	else if (this->hitPoints > 0 && this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " ran out of energy points" << std::endl;
	else if (this->hitPoints <= 0 && this->energyPoints > 0)
		std::cout << "ClapTrap " << this->name << " has run out of hit points" << std::endl;
}