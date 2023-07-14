#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default constructor called for Dog." << std::endl;
}

Dog::Dog(Dog const & other): Animal(other)
{
	std::cout << "Copy constructor called for Dog." << std::endl;
}

Dog& Dog::operator=(Dog const & other)
{
	this->Animal::operator=(other);
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark Bark" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog." << std::endl;
}