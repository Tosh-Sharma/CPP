#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
	{
		std::cout << "A generated" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "B generated" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return new C();
	}
}

void	identify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

int main() {
	std::srand(time(0));
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = generate();

	identify(*base1);
	identify(base1);
	std::cout << "Above two should be matching" << std::endl;
	identify(*base2);
	identify(base2);
	std::cout << "Above two should be matching" << std::endl;
	identify(*base3);
	identify(base3);
	std::cout << "Above two should be matching" << std::endl;
	identify(*base4);
	identify(base4);
	std::cout << "Above two should be matching" << std::endl;


    return 0;
}