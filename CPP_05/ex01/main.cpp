#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	jim("Jim", 150);
	Form form1("Form 1", 20, 20);
	Form form2("Form 2", 20, 1);
	try {
		Form form3("form 3", 0, 20);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form1;
	form1.beSigned(bob);
	std::cout << form1;
	try {
		form1.beSigned(jim);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	jim.signForm(form2);

	try {
		bob.signForm(form2);
		bob.signForm(form2);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
