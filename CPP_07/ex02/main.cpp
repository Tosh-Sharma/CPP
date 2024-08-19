#include "Array.hpp"

int	main(void) {
	Array<int>			integers(3);

	std::cout << "Initialized integers array: " << integers << std::endl;
	std::cout << "Size of integers array: " << integers.size() << std::endl;

	integers[0] = 100;
	integers[1] = 200;
	integers[2] = 300;
	std::cout << "Updated integers array: " << integers << std::endl;

	Array<int>	equalCopyArray = integers;
	std::cout << "equalCopyArray array: " << equalCopyArray << std::endl;
	try {
		equalCopyArray[4] = 42;
	} catch (std::exception &e) {
		std::cout << "ERROR MESSAGE: ";
		std::cout << e.what() << std::endl;
	}

	/*
	// Similar example for strings:
	Array<std::string>	strings(2);
	strings[0] = "Hello";
	strings[1] = "World";
	std::cout << "Original strings array " << strings << std::endl;

	const Array<std::string>	copiedStrings(strings);
	std::cout << "Original Strings array: " << strings << std::endl;
	std::cout << "Copied strings array: " << copiedStrings << std::endl;
	*/

	return 0;
}
