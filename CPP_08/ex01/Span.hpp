#pragma once

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>

typedef std::vector<int>::iterator	Iter;

class Span
{
	private:
		unsigned int		size;
		std::vector<int>	input;

	public:
		Span();
		~Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span & operator=(const Span & other);

		void	addNumber(int inputValue);
		void	addNumber(Iter start, Iter end);
		int		shortestSpan();
		int		longestSpan() const;

		unsigned int	getSize() const;

		class OutOfMemoryException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Out of memory to add number");
				}
		};

		class EmptyInputException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Cannot calculate span on empty input");
				}
		};

		class OnlyOneElementException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Cannot calculate span on only one element");
				}
		};
};
