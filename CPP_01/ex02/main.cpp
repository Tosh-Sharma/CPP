#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory Addresses of the variables\n";
	std::cout << "Original String's address is " << (void *)&str << std::endl;
	std::cout << "String Pointer's address is  " << (void *)&stringPTR << std::endl;
	std::cout << "String reference's address is " << (void *)&stringREF << std::endl;

	std::cout << "Values of the variables\n";
	std::cout << "Original String's address is " << str << std::endl;
	std::cout << "String Pointer's address is  " << *stringPTR << std::endl;
	std::cout << "String reference's address is " << stringREF << std::endl;
}