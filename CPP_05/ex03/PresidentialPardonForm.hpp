# pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm & other);
		PresidentialPardonForm & operator=(PresidentialPardonForm & other);
		void	action(Bureaucrat const & executor) const;
};
