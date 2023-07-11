#include"Fixed.hpp"

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed&value)
{
	cout << "Copy constructor called" << endl;
	*this = value;
}

Fixed::Fixed(const int value)
{
	cout << "Int constructor called" << endl;
	this->n = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
	cout << "Float constructor called" << endl;
	this->n = (int)(roundf(value * (1 << this->fractional_bits)));
}

Fixed& Fixed::operator=(const Fixed& value)
{
	cout << "Copy assignment operator called" << endl;
	this->n = value.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
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

ostream& operator<<(ostream& o, const Fixed& raw)
{
	o << raw.toFloat();
	return o;
}