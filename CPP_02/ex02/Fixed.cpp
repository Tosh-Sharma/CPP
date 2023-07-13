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

// Operator overloads for comparisons

bool	Fixed::operator>(const Fixed& comparator)
{
	return (this->getRawBits() > comparator.getRawBits());
}

bool	Fixed::operator<(const Fixed& comparator)
{
	return (this->getRawBits() < comparator.getRawBits());
}

bool	Fixed::operator<=(const Fixed& comparator)
{
	return (this->getRawBits() <= comparator.getRawBits());
}

bool	Fixed::operator>=(const Fixed& comparator)
{
	return (this->getRawBits() >= comparator.getRawBits());
}

bool	Fixed::operator==(const Fixed& comparator)
{
	return (this->getRawBits() == comparator.getRawBits());
}

bool	Fixed::operator!=(const Fixed& comparator)
{
	return (this->getRawBits() != comparator.getRawBits());
}

// Operator overloads for arithmetic operations.

Fixed	Fixed::operator+(const Fixed& a)
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + a.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& a)
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - a.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& a)
{
	Fixed	result;
	result.setRawBits((this->n * a.n) / (1 << this->fractional_bits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& a)
{
	Fixed	result;
	result.setRawBits(this->n / a.n * (1 << this->fractional_bits));
	return (result);
}

// Pre and Post increments and decrements.

Fixed&	Fixed::operator++(void)
{
	++this->n;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--this->n;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->n += 1;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->n -= 1;
	return (temp);
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if ((Fixed)a > (Fixed)b)
		return (b);
	return (a);
}

Fixed& Fixed::max(Fixed&a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed&a, const Fixed& b)
{
	if ((Fixed)a > (Fixed)b)
		return (a);
	return (b);
}
