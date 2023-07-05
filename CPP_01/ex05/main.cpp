#include "Harl.hpp"

int	main(int argc, char **argv)
{
    Harl Harl;

    Harl.complain("debug");
	cout << "\n";
    Harl.complain("info");
    cout << "\n";
	Harl.complain("warning");
    cout << "\n";
	Harl.complain("error");
	cout << "\n";
    Harl.complain("no");
	return (0);
}