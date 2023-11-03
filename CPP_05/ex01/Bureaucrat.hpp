#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string	name;
		int	grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat & other);
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat & operator=(Bureaucrat & other);
		std::string const & getName() const;
		int const & getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form & form);
		class GradeTooHighException: public std::exception {
			public:
			const char * what() const throw()
			{
				return "Grade is too high\n";
			}
		};
		class GradeTooLowException: public std::exception {
			public:
			const char * what() const throw()
			{
				return "Grade is too low\n";
			}
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat);
