#ifndef Cat_H
#define Cat_H

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(Cat const & other);
		Cat& operator=(Cat const & other);
		~Cat();

		void	makeSound(void) const;
};

#endif