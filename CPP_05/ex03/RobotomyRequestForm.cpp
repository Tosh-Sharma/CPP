#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(): Form("Default Robot", 72, 45) {
	this->target = "Default target";
}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm & other): Form(other) {}

std::string const & RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target):
	Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm & RobotomyRequestForm::
	operator=(RobotomyRequestForm & other)
{
	this->Form::operator=(other);
	return (*this);
}

void RobotomyRequestForm::action(Bureaucrat const & executor) const
{
	this->Form::execute(executor);
	if (((rand() % 100) + 1) % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " failed to robotomize." << std::endl;
}
