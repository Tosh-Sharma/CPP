#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm & other): Form(other) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target):
	Form(target, "RobotomyRequestForm", 72, 45) {}

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
