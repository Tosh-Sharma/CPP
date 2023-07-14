#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl Harl;

	Harl.complain("debug");
	std::cout << "\n";
	Harl.complain("info");
	std::cout << "\n";
	Harl.complain("warning");
	std::cout << "\n";
	Harl.complain("error");
	std::cout << "\n";
	Harl.complain("no");
	return (0);
}