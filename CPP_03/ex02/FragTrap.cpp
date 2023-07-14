#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default Constructor for FragTrap has been called." << std::endl;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor for FragTrap " << this->getName()
		<< " has been called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "Constructor called for FragTrap" << std::endl;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " would love to get a high five guys." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << this->getName() << " : ";
	this->ClapTrap::attack(target);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << this->getName() << " : ";
	this->ClapTrap::takeDamage(amount);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap " << this->getName() << " : ";
	this->ClapTrap::beRepaired(amount);
}
