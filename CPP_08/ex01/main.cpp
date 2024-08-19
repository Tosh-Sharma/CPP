#include "Span.hpp"

int main()
{
	Span				firstCase(10);
	static const int arr[] = { 22, 23, 30, 35, 47, 55, 60, 89, 99 };
	std::vector<int>	copyVector(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	try {
		firstCase.addNumber(copyVector.begin(), copyVector.end());
		firstCase.addNumber(222);
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "FirstCase outputs are" << std::endl;
		std::cout << "Size is " << firstCase.getSize() << std::endl;
		std::cout << "Shortest span: " << firstCase.shortestSpan() << std::endl;
		std::cout << "Longest span: " << firstCase.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Span	tenThousandCase(10000);
	std::srand(time(0));
	for (unsigned int i = 0; i < 10000; ++i)
		tenThousandCase.addNumber(std::rand() % 100);

	try {
		std::cout << "\nTenThousandCase outputs are" << std::endl;
		std::cout << "Size is " << tenThousandCase.getSize() << std::endl;
		std::cout << "Shortest span: " << tenThousandCase.shortestSpan() << std::endl;
		std::cout << "Longest span: " << tenThousandCase.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
