#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	length;

	public:
		Array();
		~Array();
		Array(unsigned int input);
		Array(const Array &copy);

		Array &		operator=(const Array & copy);
		T &			operator[](unsigned int index);
		const T &	operator[](unsigned int index) const;
		unsigned int	size()	const;

		class IndexOutOfBoundsException: public std::exception {
			public:
				virtual const char	*what() const throw() {
					return "Array index is out of bounds";
				}
		};
};

template <typename T>
std::ostream & operator<<(std::ostream & o, const Array<T> &array);

#include "Array.tpp"
