#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
	// NOTE: Originally we do rand % 3 to showcase the generate case.
	// But I modified it to rand % 4 to add one more case to show negative case
	int random = std::rand() % 4;
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
	else if (random == 2)
	{
		std::cout << "C generated" << std::endl;
		return new C();
	}
	else // NOTE: THIS CODE IS ADDED TO SHOW NEGATIVE CASE ONLY.
	{
		std::cout << "Base generated" << std::endl;
		return new Base();
	}
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &e) {
				std::cout << "Unknown type of casting done" << std::endl;
			}
		}
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type of casting done" << std::endl;
}

int main() {
	std::srand(time(0));
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = generate();

	identify(*base1);
	identify(base1);
	std::cout << "Above two lines should be matching" << std::endl;
	identify(*base2);
	identify(base2);
	std::cout << "Above two lines should be matching" << std::endl;
	identify(*base3);
	identify(base3);
	std::cout << "Above two lines should be matching" << std::endl;
	identify(*base4);
	identify(base4);
	std::cout << "Above two lines should be matching" << std::endl;

    return 0;
}