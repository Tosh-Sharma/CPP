# pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string	name;
		bool		isSigned;
		int			gradeToSign;
		int			gradeToExecute;
		Form();
	public:
		~Form();
		Form(Form & other);
		Form & operator=(Form & other);
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		std::string const & getName() const;
		bool const & getIsSigned() const;
		int const & getGradeToSign() const;
		int const & getGradeToExecute() const;
		void	beSigned(Bureaucrat & bureaucrat);
		class GradeTooHighException: public std::exception {
			public:
			const char * what() const throw() {
				return "Grade is too high\n";
			}
		};
		class GradeTooLowException: public std::exception {
			public:
			const char * what() const throw() {
				return "Grade is too low\n";
			}
		};
};

std::ostream & operator<<(std::ostream & o, Form const & form);
