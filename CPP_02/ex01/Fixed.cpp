#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed&value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->n = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->n = (int)(roundf(value * (1 << this->fractional_bits)));
}

Fixed& Fixed::operator=(const Fixed& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->n = value.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->n / (1 << this->fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->n >> this->fractional_bits);
}

void	Fixed::setRawBits(int raw)
{
	this->n = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->n);
}

std::ostream& operator<<(std::ostream& o, const Fixed& raw)
{
	o << raw.toFloat();
	return o;
}