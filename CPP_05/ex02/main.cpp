#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat right("Can Execute", 5);
	Bureaucrat wrong("cannot execute", 146);

	ShrubberyCreationForm home("Home");
	wrong.signForm(home);
	right.executeForm(home);

	right.signForm(home);
	wrong.executeForm(home);

	right.executeForm(home);

	RobotomyRequestForm robot("Robot");
	wrong.signForm(robot);
	right.executeForm(robot);

	right.signForm(robot);
	wrong.executeForm(robot);

	right.executeForm(robot);

	PresidentialPardonForm prezi("Hapburn boy");
	wrong.signForm(prezi);
	right.executeForm(prezi);

	right.signForm(prezi);
	wrong.executeForm(prezi);

	right.executeForm(prezi);
	return 0;
}
