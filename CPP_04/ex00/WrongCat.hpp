#ifndef WrongCat_H
#define WrongCat_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const & other);
		WrongCat& operator=(WrongCat const & other);
		~WrongCat();

		void	makeSound(void) const;
};

#endif