#include "Fixed.hpp"

Fixed::Fixed(): n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& value)
{
	std::cout << "Copy constructor called" << std::endl;
	this->n = value.n;
}

Fixed& Fixed::operator=(const Fixed& value)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	this->n = value.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->n;
}

void	Fixed::setRawBits(int const raw)
{
	this->n = raw;
}