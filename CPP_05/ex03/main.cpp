#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat right("Can Execute", 5);
	Bureaucrat wrong("cannot execute", 146);

	Form *form;
	Intern intern;

	form = intern.makeForm("ShrubberyCreationForm", "home");
	right.signForm(*form);
	right.executeForm(*form);

	try {
		form = intern.makeForm("SomethingRandomForm", "home");
		right.signForm(*form);
		right.executeForm(*form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
