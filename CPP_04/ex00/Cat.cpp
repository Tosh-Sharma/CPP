#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default constructor called for Cat." << std::endl;
}

Cat::Cat(Cat const & other): Animal(other)
{
	std::cout << "Copy constructor called for Cat." << std::endl;
}

Cat& Cat::operator=(Cat const & other)
{
	this->Animal::operator=(other);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat." << std::endl;
}