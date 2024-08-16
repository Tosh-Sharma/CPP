#pragma once

#include <iostream>
#include <vector>

class NumberClass
{
    private:
        int number;
    public:
        NumberClass();
		~NumberClass();
        NumberClass(int number);
        NumberClass & operator= (NumberClass & num);

        int getNumber() const;
        bool operator== (NumberClass const & num) const;
        bool operator!= (NumberClass const & num) const;
        bool operator> (NumberClass const & num) const;
        bool operator< (NumberClass const & num) const;
        bool operator>= (NumberClass const & num) const;
        bool operator<= (NumberClass const & num) const;
};

std::ostream & operator<<(std::ostream & o, const NumberClass &num);

template <typename T>
void iter(T *array, size_t size, void (*func)(T &)) {
	if (!array || !func || size <= 0)
		return ;

	size_t iterator = 0;
	for (; iterator < size; ++iterator)
		func(array[iterator]);
}

template <typename T>
void iter(T *array, size_t size, void (*func)(const T &)) {
	if (!array || !func || size <= 0)
		return ;

	size_t iterator = 0;
	for (; iterator < size; ++iterator)
		func(array[iterator]);
}

template <typename T>
void	display(const T &value) {
	std::cout << value << std::endl;
}
