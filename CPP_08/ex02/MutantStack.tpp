#pragma once

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {
	std::cout << "Created empty MutantStack" << std::endl;
};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & other): std::stack<T>(other)
{
	std::cout << "Created MutantStack by copy" << std::endl;
};

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Destroyed MutantStack" << std::endl;
};

template<typename T> 
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & other)
{
	if (this == &other)
		return (*this);
	std::stack<T>::operator=(other);
	return (*this);
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return this->c.cbegin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return this->c.cbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return this->c.crbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
    return this->c.crend();
}
