#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Default President", 25, 5) {
	this->target = "Default target";
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string const & PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm & other): Form(other) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target):
	Form("PresidentialPardonForm", 25, 5), target(target) {}

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
