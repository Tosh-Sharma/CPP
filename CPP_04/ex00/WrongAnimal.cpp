#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "A wrong unholy creation";
	std::cout << "Default constructor for WrongAnimal called creating "
		<< this->type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "Constructor instantiating WrongAnimal as " << type
	<< " is called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const  & other)
{
	std::cout << "Copy constructor called for WrongAnimal"
	<< std::endl;
	(*this) = other;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & other)
{
	this->type = other.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor for WrongAnimal is called." << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "** random wrong unholy sounds **" << std::endl;
}

std::string const &		WrongAnimal::getType(void) const
{
	return this->type;
}