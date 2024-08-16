#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(): array(NULL), length(0) {
	std::cout << "Empty array has been instantiated\n" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	if (array)
		delete[] array;
	std::cout << "Array has been deleted\n";
	return ;
}

template <typename T>
Array<T>::Array(unsigned int input): array(new T[input]), length(input) {
	std::cout << "Empty Array of size " << input
		<< " has been instantiated\n" << std::endl;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & copy) {
	if (this != &copy) {
		if (this->array)
		{
			delete[] this->array;
			this->array = NULL;
		}
		this->length = copy.size();
		this->array = new T[this->length];
		unsigned int iterator = 0;

		for ( ;iterator < this->length; iterator++)
			this->array[iterator] = copy.array[iterator];
	}

	return (*this);
}

template <typename T>
Array<T>::Array(const Array &copy) {
	this->length = copy.size();
    this->array = new T[this->length];
    unsigned int iterator = 0;

    for (; iterator < this->length; iterator++)
        this->array[iterator] = copy.array[iterator];
}

template <typename T>
T &		Array<T>::operator[](unsigned int index) {
	if (index >= length || index < 0)
		throw IndexOutOfBoundsException();
	return (array[index]);
}

template <typename T>
const T &	Array<T>::operator[](unsigned int index) const {
	if (index >= length || index < 0)
			throw IndexOutOfBoundsException();
		return (array[index]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return length;
}

template <typename T>
std::ostream & operator<<(std::ostream & o, const Array<T> &array) {
	if (array.size() == 0) {
		o << "Array is empty\n";
		return o;
	}
	unsigned int iterator = 0;
	o << "Elements of Array:\t";
	for (; iterator < array.size(); ++iterator) {
		o << array[iterator] << " ";
	}
	o << std::endl;
	return o;
}
