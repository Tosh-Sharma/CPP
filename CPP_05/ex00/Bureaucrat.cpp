#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Anonymous"), grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat & other)
{
	(*this) = other;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->grade = grade;
	}
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
	this->grade = other.grade;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat)
{
	return (o << bureaucrat.getName() << ", bureaucrat grade " <<
	bureaucrat.getGrade() << "." << std::endl);
}

std::string const & Bureaucrat::getName() const
{
	return (this->name);
}

int const & Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		--this->grade;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		++this->grade;
	std::cout << "Grade of " << this->getName() << "decremented to "
		<< this->getGrade() << std::endl;
}
