#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & other)
{
	*this = other;
}

RPN & RPN::operator=(const RPN & other)
{
	this->numberStack = other.numberStack;
	this->input = other.input;
	this->result = other.result;
	return (*this);
}

bool	RPN::ensureInputIsValid()
{
	bool isValid = true;

	unsigned int iterator = 0;
	for (; iterator < this->input.size(); ++iterator)
	{
		if (!isdigit(this->input[iterator]) &&
			this->input[iterator] != '+' &&
			this->input[iterator] != '-' &&
			this->input[iterator] != '*' &&
			this->input[iterator] != '/' &&
			 this->input[iterator] != ' ')
		{
			isValid = false;
			break;
		}
	}
	return isValid;
}

void	RPN::cleanUpInput()
{
	std::string cleanedInput;

	unsigned int iterator = 0;
	for (; iterator < this->input.size(); ++iterator)
	{
		if ((this->input[iterator] != ' ') ||
			(this->input[iterator] == '\t') ||
			(this->input[iterator] == '\n'))
			cleanedInput += this->input[iterator];
	}
	this->input = cleanedInput;
}

void	RPN::setInput(const char *charInput)
{
	this->input = charInput;
}

int	RPN::getNumberFromStack()
{
	if (this->numberStack.empty())
		throw std::exception();
	int value = this->numberStack.top();
	this->numberStack.pop();
	return value;
}

void	RPN::evaluatePostfix()
{
	unsigned int iterator = 0;
	for (; iterator < this->input.size(); ++iterator) {
		if (isdigit(this->input[iterator]))
		{
			int number = this->input[iterator] - '0';
			this->numberStack.push(number);
		}
		else {
			int alpha = getNumberFromStack();
			int beta = getNumberFromStack();
			if (alpha == 0 && this->input[iterator] == '/')
			{
				throw std::exception();
			}
			switch (this->input[iterator])
			{
				case '+':
					this->numberStack.push(beta + alpha);
					break;
				case '-':
					this->numberStack.push(beta - alpha);
					break;
				case '*':
					this->numberStack.push(beta * alpha);
					break;
				case '/':
					this->numberStack.push(beta / alpha);
					break;
			}
		}
	}
	this->result = getNumberFromStack();
	if (!this->numberStack.empty())
		throw std::exception();
}

int		RPN::getResult() const
{
	return this->result;
}