#include "Span.hpp"

Span::Span(void) : size(0)
{
	std::cout << "Span of size 0 created" << std::endl;
}

Span::~Span()
{
	std::cout << "Span has been destroyed" << std::endl;
}

Span::Span(unsigned int N) : size(N)
{
	std::cout << "Span of size " << N << " created" << std::endl;
}

Span::Span(const Span & other)
{
	(*this) = other;
}

Span & Span::operator=(const Span & other)
{
	if (this != &other)
	{
		this->size = other.size;
		this->input = other.input;
	}
	else if (this == &other)
		std::cout << "Self assignment" << std::endl;
	return (*this);
}

void	Span::addNumber(int inputValue)
{
	if (input.size() >= size)
		throw OutOfMemoryException();
	else
		input.push_back(inputValue);
}

void	Span::addNumber(Iter start, Iter end)
{
	if ((input.size() + std::distance(start, end)) > size)
		throw OutOfMemoryException();
	else
		input.insert(input.end(), start, end);
}

int	Span::shortestSpan()
{
	std::vector<int>	spanDifferences;

	if (input.size() < 1)
		throw EmptyInputException();
	else if (input.size() == 1)
		throw OnlyOneElementException();
	
	std::sort(input.begin(), input.end());
	unsigned int	iterator = 0;
	while (iterator < (input.size() - 1)) {
		int diff = input[iterator] - input[iterator + 1];
		if (diff < 0)
			diff *= -1;
		spanDifferences.push_back(diff);
		++iterator;
	}
	int	result = *std::min_element(
		spanDifferences.begin(), spanDifferences.end());
	return result;
}

int	Span::longestSpan() const
{
	int				largestNumber;
	int				smallestNumber;
	unsigned int	iterator = 0;

	if (input.size() < 1)
		throw EmptyInputException();
	else if (input.size() == 1)
		throw OnlyOneElementException();

	// Note: We can find max and min in one loop using the code below.
	// However, the max_element and min_element functions will take two loops
	// to find the max and min values. So, we will use just one loop for
	// better performance.

	// int	largestNumber = *std::max_element(input.begin(), input.end());
	// int	smallestNumber = *std::min_element(input.begin(), input.end());
	// std::cout << "Largest number by search is " << largestNumber << std::endl;
	// std::cout << "Smallest number by search is " << smallestNumber << std::endl;

	while (iterator < input.size()) {
		if (iterator == 0) {
			largestNumber = input[iterator];
			smallestNumber = input[iterator];
		}
		if (input[iterator] > largestNumber)
			largestNumber = input[iterator];
		if (input[iterator] < smallestNumber)
			smallestNumber = input[iterator];
		++iterator;
	}
	// std::cout << "Largest number by loop is " << largestNumber << std::endl;
	// std::cout << "Smallest number by loop is " << smallestNumber << std::endl;
	return (largestNumber - smallestNumber);
}

unsigned int	Span::getSize() const
{
	return (this->size);
}
