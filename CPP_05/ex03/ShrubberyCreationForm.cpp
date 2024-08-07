#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Default Shrubbery", 145, 137) {
  this->target = "Default target";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm & other): Form(other) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target):
	Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm & ShrubberyCreationForm::
	operator=(ShrubberyCreationForm & other)
{
	this->Form::operator=(other);
	return (*this);
}

std::string const & ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::action(Bureaucrat const & executor) const
{
	this->Form::execute(executor);
	std::ofstream	file;
	std::string		input;

	input = "\n\
      __/\\__\n\
      \\    /\n\
__/\\__/    \\__/\\__\n\
\\                /\n\
/_              _\\\n\
  \\            /\n\
__/            \\__\n\
\\                /\n\
/_  __      __  _\\\n\
  \\/  \\    /  \\/\n\
      /_  _\\\n\
        \\/\n";
  file.open(this->getTarget() + "_shruberry", std::ios::out);

  if (!file) {
    std::cout << "Error in file creation!";
  } else {
	file << input;
  }
  file.close();
}
