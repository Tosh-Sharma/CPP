#include "Base.hpp"

Base::Base() : id(0) {}

Base::~Base() {}

Base::Base(const Base &other) {
	*this = other;
}

Base & Base::operator=(const Base &other) {
	if (this != &other) {
		this->id = other.id;
	}
	return *this;
}
