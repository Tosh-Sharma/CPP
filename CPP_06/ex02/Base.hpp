#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Base{
	private:
		int var_base;
    public:
	 	Base();
		virtual ~Base();
		Base(const Base &other);
		Base &operator=(const Base &other);
};
