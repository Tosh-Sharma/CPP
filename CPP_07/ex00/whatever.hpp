#pragma once

#include<iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const & min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T const & max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

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
