#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*i =	new Cat();
	const Animal	*j = 	new Dog();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	const WrongAnimal	*metaW = new WrongAnimal();
	const WrongAnimal	*iW =	new WrongCat();

	std::cout << metaW->getType() << " " << std::endl;
	std::cout << iW->getType() << " " << std::endl;
	iW->makeSound();
	metaW->makeSound();
	return (0);
}