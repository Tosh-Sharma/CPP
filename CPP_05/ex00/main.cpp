#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 1);
	try {
		bob.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	jim("Jim", 150);
	try {
		jim.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	*jack = new Bureaucrat("Jack", 151);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	*jill = new Bureaucrat("Jill", 0);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}