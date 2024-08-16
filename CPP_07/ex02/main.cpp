#include "Array.hpp"

int	main() {
	std::cout << "Create empty int array:\n";
	Array<int>	emptyInts;
	std::cout << emptyInts << std::endl;
	
	std::cout << "\nCreate int array:\n";
	Array<int> ints(3);
	std::cout << ints << std::endl;

	std::cout << "\nFill it with '[]' operator:\n";
	std::srand(std::time(0));
	for (int i = 0; i < 3; i++)
		ints[i] = std::rand() % 100;
	std::cout << ints << std::endl;	

	std::cout << "\nFill emptyInts with '=' operator:\n";
	emptyInts = ints;
	std::cout << emptyInts << std::endl;

	std::cout << "\nModify values of ints with '[]' operator:\n";
	for (int i = 0; i < 3; i++)
		ints[i] = std::rand() % 100;

	std::cout << ints << std::endl;	
	std::cout << emptyInts << std::endl;

	std::cout << "\nCreate strings and fill it with '[]' operator:\n";
	Array<std::string>	strings(2);
	strings[0] = "Hello";
	strings[1] = "World";

	std::cout << strings << std::endl;	

	try {
		strings[2] = "Superworld";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nCreate const copiedStrings by copy constructor:\n";
	const Array<std::string>	copiedStrings(strings);

	std::cout << strings << std::endl;

	std::cout << "Modify values of strings with '[]' operator:\n";
	strings[0] = "Hello2";
	strings[1] = "World2";

	std::cout << strings << std::endl;
	std::cout << copiedStrings << std::endl;

	return (0);
}
