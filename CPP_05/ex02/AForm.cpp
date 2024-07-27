#include "AForm.hpp"

Form::Form(): name("DummyForm"), isSigned(false),
		gradeToSign(150), gradeToExecute(150) {}

Form::~Form() {}

Form::Form(Form & other): name(other.getName()), isSigned(false),
		gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(Form & other)
{
	(void)other;
	this->isSigned = false;
	return (*this);
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute): name(name), isSigned(false),
		gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

std::string const & Form::getName() const
{
	return (this->name);
}

bool const & Form::getIsSigned() const
{
	return (this->isSigned);
}

int const & Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int const & Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->gradeToExecute)
	{
		GradeTooLowException e;
		throw e;
	}
	else if (!this->getIsSigned())
	{
		NotSignedException e;
		throw e;
	}
}

void	Form::beSigned(Bureaucrat & bureaucrat)
{
	// Below lines are in case we want to throw an exception if the form is already signed
	if (this->isSigned)
	{
		CannotSignException e;
		throw e;
	}

	if (bureaucrat.getGrade() > this->gradeToSign)
	{
		GradeTooLowException e;
		throw e;
	}
	else
		this->isSigned = true;
}

std::ostream & operator<<(std::ostream & o, Form const & form)
{
	return (o << "Form " << form.getName()
		<< " is " << (form.getIsSigned() ? "signed" : "not signed")
		<< " and requires grade " << form.getGradeToSign() <<
		" to be signed and grade " << form.getGradeToExecute() <<
		" to be executed" << std::endl);
}
