#ifndef FIXED_H
#define FIXED_H

#include <iostream>

using	std::cout;
using	std::endl;

class Fixed
{
	private:
		int					n;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& value);
		Fixed& operator=(const Fixed& value);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
