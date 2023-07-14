#ifndef WrongAnimal_H
#define WrongAnimal_H

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & other);
		WrongAnimal& operator=(WrongAnimal const &);
		virtual ~WrongAnimal();

		void		makeSound(void) const;
		std::string	const&	getType(void) const;
};

#endif