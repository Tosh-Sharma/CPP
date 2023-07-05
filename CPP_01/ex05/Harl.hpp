#ifndef Harl_H
#define	Harl_H

#include <string>
#include <iostream>

using	std::string;
using	std::endl;
using	std::cout;
using	std::cin;

class Harl
{
	private:
		void	debug(void);
		void	warning(void);
		void	info(void);
		void	error(void);
	public:
		void	complain(string level);
};

#endif