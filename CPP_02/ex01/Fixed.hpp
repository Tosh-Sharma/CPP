#ifndef Fixed_H
#define Fixed_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	n;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed&value);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed& value);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(const int value);
};

std::ostream&	operator<<(std::ostream &o, const Fixed& raw);

#endif
