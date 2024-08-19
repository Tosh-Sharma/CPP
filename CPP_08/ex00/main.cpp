#include "easyfind.hpp"

int main()
{
	std::vector<int>	alpha;
	for (int i = 0; i < 5; i++)
		alpha.push_back(i + 100);

	try {
		std::cout << "Finding 102 in vector<int> alpha: ";
		std::vector<int>::iterator findValue = easyfind(alpha, 102);
		std::cout << *findValue << std::endl;
		std::cout << "Finding 107 in vector<int> alpha: ";
		std::vector<int>::iterator findValue2 = easyfind(alpha, 107);
		std::cout << *findValue2 << std::endl;
	} catch (NotFoundException e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int>	beta;
	for (int i = 0; i < 5; i++)
		beta.push_back(i + 500);
	
	try {
		std::cout << "Finding 502 in list<int> beta: ";
		std::list<int>::iterator findValue3 = easyfind(beta, 502);
		std::cout << *findValue3 << std::endl;
		std::cout << "Finding 507 in list<int> beta: ";
		std::list<int>::iterator findValue4 = easyfind(beta, 507);
		std::cout << *findValue4 << std::endl;
	} catch (NotFoundException e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}