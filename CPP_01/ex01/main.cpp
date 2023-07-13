#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

void	dummy_code();
int	main(void)
{
	std::cout << "Running dummy code"  << std::endl;
	dummy_code();
	// Uncomment below line to test for leaks.
	// system("leaks output");
	return (0);
}

void	dummy_code(void)
{
	int	N = 5;

	Zombie *horde = zombieHorde(N ,"Horder");
	delete[] horde;
}
