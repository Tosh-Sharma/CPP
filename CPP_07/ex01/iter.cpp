#include "iter.hpp"

NumberClass::NumberClass() : number(0) {}

NumberClass::NumberClass(int number) : number(number) {}

NumberClass & NumberClass::operator= (NumberClass & num)
{
	number = num.getNumber();
	return *this;
}

NumberClass::~NumberClass() {}

int NumberClass::getNumber() const {
	return number;
}

bool NumberClass::operator== (NumberClass const & num) const {
	return (this->number == num.number);
}

bool NumberClass::operator!= (NumberClass const & num) const {
	return (this->number != num.number);
}

bool NumberClass::operator> (NumberClass const & num) const {
	return (this->number > num.number);
}

bool NumberClass::operator< (NumberClass const & num) const {
	return (this->number < num.number);
}

bool NumberClass::operator>= (NumberClass const & num) const {
	return (this->number >= num.number);
}

bool NumberClass::operator<= (NumberClass const & num) const {
	return (this->number <= num.number);
}

std::ostream & operator<<(std::ostream & o, const NumberClass &num) {
	o << num.getNumber();
	return o;
}
