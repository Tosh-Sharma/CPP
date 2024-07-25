# pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm & other);
		PresidentialPardonForm & operator=(PresidentialPardonForm & other);

		void	action(Bureaucrat const & executor) const;
		std::string const & getTarget() const;
};
