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
		// (void)jim;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	*jack = new Bureaucrat("Jack", 151);
		(void)jack;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	*jill = new Bureaucrat("Jill", 0);
		(void)jill;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	*smartJack = new Bureaucrat("Smart Jack", 149);
	(void)smartJack;

	Bureaucrat	*smartJill = new Bureaucrat("Jill", 2);
	(void)smartJill;
}
