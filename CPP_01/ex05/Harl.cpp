#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {
		"warning",
		"debug",
		"info",
		"error"
	};

	void (Harl::*functions[4])() = {
		&Harl::warning,
		&Harl::debug,
		&Harl::info,
		&Harl::error
	};

	void	(Harl::*assigned_function)() = NULL;
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			assigned_function = functions[i];
	}
	if (assigned_function != NULL)
		(this->*assigned_function)();
}
