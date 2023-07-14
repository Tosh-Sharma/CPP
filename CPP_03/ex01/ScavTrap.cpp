#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default construtor for ScavTrap has been called." << std::endl;
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for ScavTrap " << this->getName()
		<< " has been called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Constructor called for ScavTrap" << std::endl;
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
}

ScavTrap::ScavTrap(ScavTrap const &rhs): ClapTrap(rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment constructor called for ScavTrap" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< this->getName() << " is now in gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << this->getName() << " : ";
	this->ClapTrap::attack(target);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->getName() << " : ";
	this->ClapTrap::takeDamage(amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << this->getName() << " : ";
	this->ClapTrap::beRepaired(amount);
}
