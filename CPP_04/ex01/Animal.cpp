#include "Animal.hpp"

Animal::Animal()
{
	this->type = "An unholy creation";
	std::cout << "Default constructor for Animal called creating "
		<< this->type << std::endl;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "Constructor instantiating Animal as " << type
	<< " is called." << std::endl;
}

Animal::Animal(Animal const  & other)
{
	std::cout << "Copy constructor called for Animal"
	<< std::endl;
	(*this) = other;
}

Animal&	Animal::operator=(Animal const & other)
{
	this->type = other.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor for Animal is called." << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "** random unholy sounds **" << std::endl;
}

std::string const &		Animal::getType(void) const
{
	return this->type;
}