#pragma once

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>     numberStack;
		std::string		 	input;
		int					result;

	public:
		RPN();
		~RPN();
		RPN(const RPN & other);
		RPN & operator=(const RPN & other);

		void	setInput(const char *charInput);
		bool	ensureInputIsValid();
		void	cleanUpInput();
		int		getResult() const;
		void	evaluatePostfix();
		int		getNumberFromStack();
};
