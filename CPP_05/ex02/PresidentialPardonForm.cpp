#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm & other): Form(other) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target):
	Form(target, "PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm & PresidentialPardonForm::
	operator=(PresidentialPardonForm & other)
{
	this->Form::operator=(other);
	return (*this);
}

void PresidentialPardonForm::action(Bureaucrat const & executor) const
{
	this->Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}
