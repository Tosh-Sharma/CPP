#include "Array.hpp"

int	main() {
	Array<int>			emptyArray;
	Array<int>			integers(3);
	Array<std::string>	strings(2);

	std::srand(std::time(0));

	std::cout << "Initialized integers array: " << std::endl;
	std::cout << integers << std::endl;
	std::cout << "Size of integers array: " << integers.size() << std::endl;

	for (int i = 0; i < 3; i++)
		integers[i] = std::rand() % 100;

	std::cout << "\nUpdated integers array: " << std::endl;
	std::cout << integers << std::endl;	

	std::cout << "Copy integers array to empty array with '=' operator:\n";
	emptyArray = integers;
	std::cout << "Filled Empty array: " << std::endl;
	std::cout << emptyArray << std::endl;

	std::cout << "\nModify values of integers array with [] operator:\n";
	for (int i = 0; i < 3; i++)
		integers[i] = std::rand() % 100;

	std::cout << "Filled Integers array: " << std::endl;
	std::cout << integers << std::endl;
	std::cout << "Filled Empty array: " << std::endl;
	std::cout << emptyArray << std::endl;

	std::cout << "\nCreate strings and fill it with '[]' operator:\n";
	strings[0] = "Hello";
	strings[1] = "World";
	std::cout << "Original String array: " << std::endl;
	std::cout << strings << std::endl;

	std::cout << "Modify values of strings with '[]' operator:\n";
	strings[0] = "Hello2";
	strings[1] = "World2";

	std::cout << "String array: " << std::endl;
	std::cout << strings << std::endl;

	std::cout << "\nTrying to access out of bound index of integers array:\n";
	try {
		integers[4] = 42;
	} catch (std::exception &e) {
		std::cout << "ERROR MESSAGE: ";
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nCreate copiedStrings by copy constructor:" << std::endl;
	const Array<std::string>	copiedStrings(strings);

	std::cout << "Original String array: " << std::endl;
	std::cout << strings << std::endl;
	std::cout << "\nCopied String array: " << std::endl;
	std::cout << copiedStrings << std::endl;

	return 0;
}
