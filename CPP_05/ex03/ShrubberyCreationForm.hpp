# pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm & other);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm & other);
		ShrubberyCreationForm(std::string const & target);
		void	action(Bureaucrat const & executor) const;
};

