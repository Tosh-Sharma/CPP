#include "Contact.hpp"

int	Contact::set_contact(std::string first_name,
	std::string last_name, std::string nick_name,
	std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	return (0);
};

std::string Contact::get_fname() const
{
	return this->first_name;
}

std::string Contact::get_lname() const
{
	return this->last_name;
}

std::string Contact::get_nname() const
{
	return this->nick_name;
}

std::string Contact::get_secret() const
{
	return this->darkest_secret;
}

std::string Contact::get_number() const
{
	return this->phone_number;
}

void Contact::display_contact() const
{
	std::cout << "First Name		: " << get_fname() << std::endl;
	std::cout << "Last Name		: " << get_lname() << std::endl;
	std::cout << "Nick Name		: " << get_nname() << std::endl;
	std::cout << "Phone Num 		: " << get_number() << std::endl;
	std::cout << "Darkest Secret	: " << get_secret() << std::endl;
}

bool Contact::is_empty() const
{
	if (Contact::get_fname().length() > 0)
		return (false);
	return (true);
}
