#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern & other)
{
	(*this) = other;
}

Intern & Intern::operator=(Intern & other)
{
	(*this) = other;
	return (*this);
}

enum form_names {
	eShrubberyCreationForm,
	eRobotomyRequestForm,
	ePresidentialPardonForm,
	eRandom,
};

form_names hashit(std::string const & input) {
	if (input == "ShrubberyCreationForm") return eShrubberyCreationForm;
	if (input == "RobotomyRequestForm") return eRobotomyRequestForm;
	if (input == "PresidentialPardonForm") return ePresidentialPardonForm;
	return eRandom;
}

Form * Intern::makeForm(std::string const & name, std::string const & target)
{
	Form *form;

	switch(hashit(name)) {
		case eShrubberyCreationForm:
		form = new ShrubberyCreationForm(target);
		break;
		case eRobotomyRequestForm:
			form = new RobotomyRequestForm(target);
			break;
		case ePresidentialPardonForm:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::UnknownFormException();
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}