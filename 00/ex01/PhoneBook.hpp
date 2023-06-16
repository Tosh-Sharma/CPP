#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>

#define SIZE 3

using std::cin;
using std::size_t;
using std::getline;
using std::tolower;
using std::setw;

class PhoneBook
{
	private:
		Contact	contacts[SIZE];
		int		index;
		void	add_contact();
		void	search_contact();
		string	store_input(string input);
		void	print_contacts();
		string	truncate_str(string str);
	
	public:
		PhoneBook();
		void	run_phb();
};

#endif