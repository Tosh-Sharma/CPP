#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

string	PhoneBook::store_input(string input)
{
	while (1)
	{
		getline(cin, input);
		if (input.length() > 0)
			break ;
	}
	return input;
}

void	PhoneBook::add_contact()
{
	string first_name, last_name, nick_name, phone_number, darkest_secret;

	cout << "You want to add a contact\n";
	cout << "Enter First Name\n";
	first_name = store_input(first_name);
	cout << "Enter Last Name\n";
	last_name = store_input(last_name);
	cout << "Enter Nick Name\n";
	nick_name = store_input(nick_name);
	cout << "Enter Phone Number\n";
	phone_number = store_input(phone_number);
	cout << "Enter Darkest Secret\n";
	darkest_secret = store_input(darkest_secret);
	contacts[index].set_contact(first_name,
		last_name, nick_name, phone_number, darkest_secret);
	index = (index + 1) % SIZE;
}

string	PhoneBook::truncate_str(string str)
{
	string output;

	if (str.length() > 9)
	{
		for(int i = 0; i < 9; ++i)
		{
			output += str[i];
		}
		output += '.';
	}
	else
	{
		size_t space_count = 10 - str.length();
		for (size_t j = 0; j < space_count; ++j)
			output += ' ';
		for (size_t i = 0; i < str.length(); ++i)
			output += str[i];
	}
	return (output);
}

/**
 * TODO: NEED A LOGIC TO STORE ELEMENTS and display them if they aren't empty
*/
void	PhoneBook::print_contacts()
{
	cout << "INDEX is " << index << endl;
	cout << "     Index|first name| last name| nick name\n";
	for (int i = 0; i < index; ++i)
	{
		cout << setw(10) << i << "|" <<
			truncate_str(contacts[i].get_fname()) << "|" <<
			truncate_str(contacts[i].get_lname()) << "|" <<
			truncate_str(contacts[i].get_nname()) << endl;
	}
}

void	PhoneBook::search_contact()
{
	string	input;
	int		num;

	print_contacts();
	cout << "Enter index from 1 to 8 to retrieve data\n";
	while (1)
	{
		getline(cin, input);
		try
		{
			num = std::stoi(input);
			if (num > 8 || num < 1)
				std::cerr << "The index is outside of the range we have. Retry." << endl;
			else
			{
				contacts[num - 1].display_contact();
				break ;
			}
		}
		catch (const std::invalid_argument& e) {
        	std::cerr << "Enter a valid number." << endl;
    	}
		catch (const std::out_of_range& e) {
        	std::cerr << "Too big to be considered in our input." << endl;
	    }
	}
}

void	PhoneBook::run_phb()
{
	while (1)
	{
		string	input;
		string	lower_input;

		cout << "What would you like to do?\n";
		cout << "1. Add\n2. Search\n3. Exit\n";
		getline(cin, input);
		for (size_t i = 0; i < input.length(); i++)
		{
			lower_input += (char)tolower(input[i]);
		}
		if (lower_input.compare("add") == 0)
			add_contact();
		else if (lower_input.compare("search") == 0)
			search_contact();
		else if (lower_input.compare("exit") == 0)
			break ;
	}
}
