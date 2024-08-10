#pragma once

#include <iostream>

class Base{
	private:
		int id;
    public:
	 	Base();
		virtual ~Base();
		Base(const Base &other);
		Base &operator=(const Base &other);
};
