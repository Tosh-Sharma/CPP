#ifndef Fixed_H
#define Fixed_H

#include <iostream>
#include <cmath>

using	std::string;
using	std::cout;
using	std::endl;
using	 std::ostream;

class Fixed
{
	private:
		int	n;
		static const int fractional_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed&value);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed& value);

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(const int value);

		bool	operator>(const Fixed& comparator);
		bool	operator<(const Fixed& comparator);
		bool	operator<=(const Fixed& comparator);
		bool	operator>=(const Fixed& comparator);
		bool	operator==(const Fixed& comparator);
		bool	operator!=(const Fixed& comparator);

		Fixed	operator+(const Fixed& a);
		Fixed	operator-(const Fixed& a);
		Fixed	operator*(const Fixed& a);
		Fixed	operator/(const Fixed& a);

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed&a, Fixed& b);
		static const Fixed& max(const Fixed&a, const Fixed& b);
};

ostream&	operator<<(ostream &o, const Fixed& raw);

#endif
