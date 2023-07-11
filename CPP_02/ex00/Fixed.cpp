#include "Fixed.hpp"

Fixed::Fixed(): n(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& value)
{
	cout << "Copy constructor called" << endl;
	this->n = value.n;
}

Fixed& Fixed::operator=(const Fixed& value)
{
	cout << "Copy assignment constructor called" << endl;
	this->n = value.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return this->n;
}

void	Fixed::setRawBits(int const raw)
{
	this->n = raw;
}