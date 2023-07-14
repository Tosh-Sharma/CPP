#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called for WrongCat." << std::endl;
}

WrongCat::WrongCat(WrongCat const & other): WrongAnimal(other)
{
	std::cout << "Copy constructor called for WrongCat." << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & other)
{
	this->WrongAnimal::operator=(other);
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow meow" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat." << std::endl;
}