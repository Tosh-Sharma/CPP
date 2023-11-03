#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat & other)
{
	(*this) = other;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->name = name;
		this->grade = grade;
	}
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat & other)
{
	this->name = other.name;
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

void	Bureaucrat::signForm(Form & form)
{
	if (form.getGradeToSign() < this->getGrade())
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because his grade is too low" << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName()
			<< std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try {
		form.action(*this);
		std::cout << this->getName() << " executed " << form.getName()
		<< std::endl;
	} catch (std::exception & e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}