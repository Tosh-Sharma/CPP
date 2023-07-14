#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>

#define SIZE 8

class PhoneBook
{
	private:
		Contact		contacts[SIZE];
		int			index;
		void		add_contact();
		void		search_contact();
		std::string	store_input(std::string input);
		void		print_contacts();
		std::string	truncate_str(std::string str);
	
	public:
		PhoneBook();
		int			max_index;
		void	run_phb();
};

#endif