#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
private:
	std::string			first_name;
	std::string			last_name;
	std::string			nick_name;
	std::string			phone_number;
	std::string			darkest_secret;
	
public:
	int	set_contact(std::string first_name, std::string last_name,
		std::string nick_name, std::string phone_number, 
		std::string darkest_secret);
	void	display_contact() const;
	std::string	get_fname() const;
	bool	is_empty() const;
	std::string	get_lname() const;
	std::string	get_nname() const;
	std::string	get_number() const;
	std::string	get_secret() const;
};

#endif