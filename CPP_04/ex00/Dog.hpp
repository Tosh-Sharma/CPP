#ifndef Dog_H
#define	Dog_H

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog const & other);
		Dog& operator=(Dog const & other);
		~Dog();

		void	makeSound(void) const;
};

#endif