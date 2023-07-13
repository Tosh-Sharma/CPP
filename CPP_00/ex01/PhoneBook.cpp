#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

std::string	PhoneBook::store_input(std::string input)
{
	while (1)
	{
		std::getline(std::cin, input);
		if (input.length() > 0)
			break ;
	}
	return input;
}

void	PhoneBook::add_contact()
{
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;

	std::cout << "You want to add a contact\n";
	std::cout << "Enter First Name\n";
	first_name = store_input(first_name);
	std::cout << "Enter Last Name\n";
	last_name = store_input(last_name);
	std::cout << "Enter Nick Name\n";
	nick_name = store_input(nick_name);
	std::cout << "Enter Phone Number\n";
	phone_number = store_input(phone_number);
	std::cout << "Enter Darkest Secret\n";
	darkest_secret = store_input(darkest_secret);
	contacts[index].set_contact(first_name,
		last_name, nick_name, phone_number, darkest_secret);
	index = (index + 1) % SIZE;
}

std::string	PhoneBook::truncate_str(std::string str)
{
	std::string output;

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
		std::size_t space_count = 10 - str.length();
		for (std::size_t j = 0; j < space_count; ++j)
			output += ' ';
		for (std::size_t i = 0; i < str.length(); ++i)
			output += str[i];
	}
	return (output);
}

void	PhoneBook::print_contacts()
{
	std::cout << "INDEX is " << index << std::endl;
	std::cout << "     Index|first name| last name| nick name\n";
	for (int i = 0; i < SIZE; ++i)
	{
		if (contacts[i].is_empty() == false)
		{
			std::cout << std::setw(10) << i << "|" <<
			truncate_str(contacts[i].get_fname()) << "|" <<
			truncate_str(contacts[i].get_lname()) << "|" <<
			truncate_str(contacts[i].get_nname()) << std::endl;
		}
	}
}

void	PhoneBook::search_contact()
{
	std::string	input;
	int		num;

	print_contacts();
	std::cout << "Enter index from 1 to " << SIZE << " to retrieve data\n";
	while (1)
	{
		std::getline(std::cin, input);
		try
		{
			num = std::stoi(input);
			if (num > SIZE || num < 1)
				std::cerr << "The index is outside of the range we have. Retry." << std::endl;
			else
			{
				contacts[num - 1].display_contact();
				break ;
			}
		}
		catch (const std::invalid_argument& e) {
        	std::cerr << "Enter a valid number." << std::endl;
    	}
		catch (const std::out_of_range& e) {
        	std::cerr << "Too big to be considered in our input." << std::endl;
	    }
	}
}

void	PhoneBook::run_phb()
{
	while (1)
	{
		std::string	input;
		std::string	lower_input;

		std::cout << "What would you like to do?\n";
		std::cout << "1. Add\n2. Search\n3. Exit\n";
		std::getline(std::cin, input);
		for (std::size_t i = 0; i < input.length(); i++)
		{
			lower_input += (char)std::tolower(input[i]);
		}
		if (lower_input.compare("add") == 0)
			add_contact();
		else if (lower_input.compare("search") == 0)
			search_contact();
		else if (lower_input.compare("exit") == 0)
			break ;
	}
}
