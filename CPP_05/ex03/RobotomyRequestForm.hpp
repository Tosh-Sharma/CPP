# pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm & other);
		RobotomyRequestForm & operator=(RobotomyRequestForm & other);
		void	action(Bureaucrat const & executor) const;
};