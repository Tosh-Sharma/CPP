#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Contact
{
private:
	string			first_name;
	string			last_name;
	string			nick_name;
	string			phone_number;
	string			darkest_secret;
	
public:
	int	set_contact(string first_name, string last_name,
		string nick_name, string phone_number, 
		string darkest_secret);
	void	display_contact() const;
	string	get_fname() const;
	bool	is_empty() const;
	string	get_lname() const;
	string	get_nname() const;
	string	get_number() const;
	string	get_secret() const;
};

#endif