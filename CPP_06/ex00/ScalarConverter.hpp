#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <limits>

class ScalarConverter {
	private:
		std::string originalInput;
		double		doubleInput;
		char		charInput;
		int			intInput;
		float		floatInput;

		std::string charErrorMessage;
		std::string intErrorMessage;
		std::string floatErrorMessage;
		std::string doubleErrorMessage;

	public:
		ScalarConverter();
		ScalarConverter(std::string str);
		ScalarConverter(ScalarConverter const & other);
		ScalarConverter	&operator=(ScalarConverter const & other);
		~ScalarConverter();

		void	convert();
		void	convertToChar();

		void	handleChars();
		void	handleNumbers();
		void	handleInt();
		void	handleFloat();
		void	handleDouble();

		std::string	appendSuffix();

		bool	isInteger(const std::string& str);
		bool	isFloat(const std::string& str);
		bool	isDouble(const std::string& str);

		void	displayPseudoLiteralForDouble(std::string pseudoLiteral);
		void	displayPseudoLiteralForFloat(std::string pseudoLiteral);
};