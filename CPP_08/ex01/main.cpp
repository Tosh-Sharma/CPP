#include "Span.hpp"

int main()
{
	Span	span(5);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	Span	span2(10);
	static const int arr[] = { 22, 23, 30, 35, 47, 55, 60, 89, 99 };
	// Shortest span is 23 - 22 = 1
	// Longest span is 99 - 22 = 77

	std::vector<int>	copyVector(arr, arr + (sizeof(arr) / sizeof(arr[0])));

	// Below case demonstrates adding multiple values together via 
	// AddNumber(Iter start, Iter end)
	// We can also use it to test exception handling on adding more than the size
	try {
		span2.addNumber(copyVector.begin(), copyVector.end());
		span2.addNumber(222);
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\nOutput for span2 is" << std::endl;
		std::cout << "Size is " << span2.getSize() << std::endl;
		std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span2.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Span	span3(10000);
	for (unsigned int i = 0; i < 10000; ++i)
		span3.addNumber(i + 100);

	try {
		std::cout << "\nOutput for span3 is" << std::endl;
		std::cout << "Size is " << span3.getSize() << std::endl;
		std::cout << "Shortest span: " << span3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span3.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
