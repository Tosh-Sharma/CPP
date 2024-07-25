# pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm & other);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm & other);
		ShrubberyCreationForm(std::string const & target);
		void	action(Bureaucrat const & executor) const;
		std::string const & getTarget() const;
};
