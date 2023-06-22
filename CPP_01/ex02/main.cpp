#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

int	main(void)
{
	string	str = "HI THIS IS BRAIN";
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout << "Memory Addresses of the variables\n";
	cout << "Original String's address is " << (void *)&str << endl;
	cout << "String Pointer's address is  " << (void *)&stringPTR << endl;
	cout << "String reference's address is " << (void *)&stringREF << endl;

	cout << "Values of the variables\n";
	cout << "Original String's address is " << str << endl;
	cout << "String Pointer's address is  " << *stringPTR << endl;
	cout << "String reference's address is " << stringREF << endl;
}