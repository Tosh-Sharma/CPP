#include "Form.hpp"

Form::Form(): name(""), isSigned(false),
		gradeToSign(150), gradeToExecute(150) {}

Form::~Form() {}

Form::Form(Form & other)
{
	(*this) = other;
}

Form & Form::operator=(Form & other)
{
	this->name = other.name;
	this->isSigned = other.isSigned;
	this->gradeToSign = other.gradeToSign;
	this->gradeToExecute = other.gradeToExecute;
	return (*this);
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else
	{
		this->name = name;
		this->isSigned = false;
		this->gradeToSign = gradeToSign;
		this->gradeToExecute = gradeToExecute;
	}
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

void	Form::beSigned(Bureaucrat & bureaucrat)
{
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
