# pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm & other);
		RobotomyRequestForm & operator=(RobotomyRequestForm & other);

		void	action(Bureaucrat const & executor) const;
		std::string const & getTarget() const;
};