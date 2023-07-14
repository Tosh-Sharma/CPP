#ifndef Animal_H
#define Animal_H

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & other);
		Animal& operator=(Animal const &);
		virtual ~Animal();

		virtual void		makeSound(void) const;
		std::string	const&	getType(void) const;
};

#endif