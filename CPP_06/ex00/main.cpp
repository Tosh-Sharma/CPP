#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Only one argument is allowed" << std::endl;
		return (1);
	}
	std::string	input = argv[1];
	input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
	ScalarConverter *scalarConverter = new ScalarConverter(input);
	scalarConverter->convert();
	return (0);
}
