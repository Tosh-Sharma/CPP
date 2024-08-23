#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error";
		return (1);
	}
	else
	{
		RPN rpn;
		rpn.setInput(argv[1]);
		if (!rpn.ensureInputIsValid())
		{
			std::cerr << "Error";
			return (1);
		}
		try {
			rpn.cleanUpInput();
			rpn.evaluatePostfix();
			std::cout << rpn.getResult() << std::endl;
		} catch(const std::exception& e) {
			std::cerr << "Error";
		}
	}
}
