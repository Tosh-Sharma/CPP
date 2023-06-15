#include "Contact.hpp"

int	Contact::set_contact(string first_name,
	string last_name, string nick_name,
	string phone_number, string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	return (0);
};

string Contact::get_fname() const
{
	return this->first_name;
}

string Contact::get_lname() const
{
	return this->last_name;
}

string Contact::get_nname() const
{
	return this->nick_name;
}

string Contact::get_secret() const
{
	return this->darkest_secret;
}

string Contact::get_number() const
{
	return this->phone_number;
}

void Contact::display_contact() const
{
	cout << "First Name: " << get_fname() << endl;
	cout << "Last Name : " << get_lname() << endl;
	cout << "Nick Name : " << get_nname() << endl;
	cout << "Phone Num : " << get_number() << endl;
}
