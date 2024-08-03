#include "Base.hpp"

Base::Base() : var_base(0) {}

Base::~Base() {}

Base::Base(const Base &other) {
	*this = other;
}

Base & Base::operator=(const Base &other) {
	if (this != &other) {
		this->var_base = other.var_base;
	}
	return *this;
}
