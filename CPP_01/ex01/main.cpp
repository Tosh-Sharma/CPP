#include "Zombie.hpp"

Zombie	*zombieHorde(int N, string name);

void	dummy_code();
int	main(void)
{
	cout << "Running dummy code"  << endl;
	dummy_code();
	// Comment below line to test for leaks.
	// system("leaks output");
	return (0);
}

void	dummy_code(void)
{
	int	N = 5;

	Zombie *horde = zombieHorde(N ,"Horder");
	delete[] horde;
}
