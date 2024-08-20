#pragma once

#include <vector>
#include <list>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return "Given value not found\n";
		}
};

template<typename T>
typename T::iterator easyfind(T &reference, int value)
{
	// try {
		typename T::iterator	iterator;
		iterator = std::find(reference.begin(), reference.end(), value);

		if (iterator == reference.end())
			throw NotFoundException();
		else
			return (iterator);
	// } catch (exception &e) {
	// 	if (e == NotFoundException)
	// 		std::cout << << e.what();
	// 		// throw e;
	// 	else
	// 	{
	// 		std::cout << "Unknown error occured" e.what();
	// 		// throw e;
	// 	}
	// }
}

// Note for evaluation: 
// Above throw errors that are commented out are for templating to catch unknown errors 
// being thrown. 
// If needed, we can remove the try-catch block and uncomment the throws.