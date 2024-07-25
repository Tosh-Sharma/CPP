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

	Form *form2;
	try {
		form2 = intern.makeForm("SomethingRandomForm", "home");
		right.signForm(*form2);
		right.executeForm(*form2);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
