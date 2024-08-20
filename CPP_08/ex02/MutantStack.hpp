#pragma once

#include <iostream>
#include <stack>
// Below header is not required on MacOS. But in case of Linux, it might be.
// #include <algorithm>
#include <list>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & other);
		MutantStack & operator=(const MutantStack & other);

		typedef typename std::stack<T>::
			container_type::iterator			iterator;
		typedef typename std::stack<T>::
			container_type::const_iterator		const_iterator;

		typedef typename std::stack<T>::
			container_type::reverse_iterator	reverse_iterator;
		typedef typename std::stack<T>::
		container_type::const_reverse_iterator	const_reverse_iterator;
	
		iterator	begin();
		iterator	end();

		const_iterator	cbegin() const;
		const_iterator	cend() const;

		reverse_iterator	rbegin();
		reverse_iterator	rend();

		const_reverse_iterator	crbegin() const;
		const_reverse_iterator	crend() const;
};

#include "MutantStack.tpp"
