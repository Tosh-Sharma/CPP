#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	this->originalInput = "";
}

ScalarConverter::ScalarConverter(std::string str) {
	this->originalInput = str;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other) {
	this->originalInput = other.originalInput;
    return (*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	(*this) = other;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

std::string	ScalarConverter::appendSuffix() {
	bool isInt = this->isInteger(this->originalInput);
	if (isInt)
		return (".0");
	return ("");
}

void	ScalarConverter::displayPseudoLiteralForFloat(std::string pseudoLiteral) {
	std::cout << "float: ";
	if (pseudoLiteral == "nan" || pseudoLiteral == "nanf") {
		std::cout << "nanf" << std::endl;
	} else if (pseudoLiteral == "inf" || pseudoLiteral == "+inf" || pseudoLiteral == "inff" || pseudoLiteral == "+inff") {
		std::cout << "inff" << std::endl;
	} else if (pseudoLiteral == "-inf" || pseudoLiteral == "-inff") {
		std::cout << "-inff" << std::endl;
	}
}

void	ScalarConverter::displayPseudoLiteralForDouble(std::string pseudoLiteral) {
	std::cout << "double: ";
	if (pseudoLiteral == "nan" || pseudoLiteral == "nanf") {
		std::cout << "nan" << std::endl;
	} else if (pseudoLiteral == "inf" || pseudoLiteral == "+inf" || pseudoLiteral == "-inf") {
		std::cout << "inf" << std::endl;
	} else if (pseudoLiteral == "-inff" || pseudoLiteral == "inff" || pseudoLiteral == "+inff") {
		std::cout << pseudoLiteral << std::endl;
	}
}

bool ScalarConverter::isInteger(const std::string& str)
{
	bool result = true;
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+') {
		i = 1;
	}
	for (; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			result = false;
	}
	return result;
}

bool ScalarConverter::isFloat(const std::string& str) {
	const char last_char = str[str.length() - 1];
	bool hasFloatNotation = false;
	if (last_char == 'f' || last_char == 'F') {
		if (str.length() == 1)
			hasFloatNotation = false;
		hasFloatNotation = true;
	}
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+') {
		i = 1;
	}
	for (; i < str.length() - 1; ++i) {
		if (!isdigit(str[i]) && str[i] != '.')
			return false;
	}
	return hasFloatNotation;
}

bool ScalarConverter::isDouble(const std::string& str) {
	bool hasChars = false;
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+') {
		i = 1;
	}

	for (; i < str.length(); ++i) {
		if (!isdigit(str[i]) && str[i] != '.') {
			hasChars = true;
			break;
		}
	}
	return !hasChars;
}

void ScalarConverter::convertToChar() {
	if (this->intInput >= 33 && this->intInput <= 126)
		this->charInput = static_cast<char>(this->intInput);
	else if (this->intInput >= 0 && this->intInput <= 127)
		this->charErrorMessage = "Non displayable";
	else
		this->charErrorMessage = "impossible";
	if (this->charInput)
		std::cout << "char: \'" << this->charInput << "\'" << std::endl;
	else
		std::cout << "char: " << this->charErrorMessage << std::endl;
}

void	ScalarConverter::handleChars() {
	char c = this->originalInput[0];
	if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << this->appendSuffix() << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << this->appendSuffix() << std::endl;
}

void	ScalarConverter::handleInt() {
	this->convertToChar();
	std::cout << "int: " << this->intInput << std::endl;
	std::cout << "float: " << this->floatInput << this->appendSuffix() << "f" << std::endl;
	std::cout << "double: " << this->doubleInput << this->appendSuffix() << std::endl;
}

void	ScalarConverter::handleFloat() {
	this->convertToChar();
	std::cout << "int: " << this->intInput << std::endl;
	std::cout << "float: " << this->floatInput << "f" << std::endl;
	std::cout << "double: " << this->doubleInput << this->appendSuffix() << std::endl;
}

void	ScalarConverter::handleDouble() {
	this->convertToChar();
	std::cout << "int: " << this->intInput << std::endl;
	std::cout << "float: " << this->floatInput << this->appendSuffix() << "f" << std::endl;
	std::cout << "double: " << this->doubleInput << this->appendSuffix() << std::endl;
}

void	ScalarConverter::handleNumbers() {
	if (isInteger(this->originalInput)) {
		this->intInput = std::stoi(this->originalInput);
		this->floatInput = static_cast<float>(this->intInput);
		this->doubleInput = static_cast<double>(this->intInput);
		this->handleInt();
	} else if (isFloat(this->originalInput)) {
		this->floatInput = std::stof(this->originalInput);
		this->intInput = static_cast<int>(this->floatInput);
		this->doubleInput = static_cast<double>(this->floatInput);
		this->handleFloat();
	} else if (isDouble(this->originalInput)) {
		this->doubleInput = std::stod(this->originalInput);
		this->intInput = static_cast<int>(this->doubleInput);
		this->floatInput = static_cast<float>(this->doubleInput);
		this->handleDouble();
	}
}

void	ScalarConverter::convert() {
	std::string const impossible = "impossible";
	std::string const nonDisplayable = "Non displayable";

	std::string const pseudoLiterals[8] = {
		"nan", "nanf", "inf", "+inf", "-inf", "inff", "+inff", "-inff",
	};
	for (int i = 0; i < 8; i++) {
		if (this->originalInput == pseudoLiterals[i]) {
			std::cout << "char: " << impossible << std::endl;
			std::cout << "int: " << impossible << std::endl;
			this->displayPseudoLiteralForFloat(this->originalInput);
			this->displayPseudoLiteralForDouble(this->originalInput);
			return ;
		}
	}
	if (isdigit(this->originalInput[0]) || (this->originalInput[0] == '-' || this->originalInput[0] == '+')) {
		this->handleNumbers();
	} else if (this->originalInput.length() == 1 && !isdigit(this->originalInput[0])) {
		this->handleChars();
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
