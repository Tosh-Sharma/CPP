#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern & other);
		Intern & operator=(Intern & other);
		Form * makeForm(std::string const & name, std::string const & target);
		class UnknownFormException: public std::exception {
			public:
			const char * what() const throw() {
				return "This form does not exist\n";
			}
		};
};
