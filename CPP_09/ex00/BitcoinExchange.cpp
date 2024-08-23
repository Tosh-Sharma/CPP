#include "BitcoinExchange.hpp"

/*	BitcoinExchange constructors	*/
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

// All my functions.
std::vector<std::string> BitcoinExchange::split(const std::string &s, char delimiter)
{
    std::vector<std::string> result;
    std::string temp;

    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        if (*it == delimiter)
        {
            if (!temp.empty())
            {
                result.push_back(temp);
                temp.clear();
            }
        }
        else
            temp += *it;
    }
    if (!temp.empty())
        result.push_back(temp);
    return result;
}

std::string BitcoinExchange::trim(const std::string &s)
{
    std::string::size_type start = s.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
    {
        return "";
    }
    std::string::size_type end = s.find_last_not_of(" \t\n\r\f\v");
    return s.substr(start, end - start + 1);
}

void BitcoinExchange::printRates() const {
	for (std::map<std::string, double>::const_iterator it = rate.begin(); it != rate.end(); ++it) {
		std::cout << it->first << ", " << it->second << std::endl;
	}
}

std::string	BitcoinExchange::formatDateToYYYYMMDD(std::string date)
{
	std::vector<std::string> v = this->split(date, '-');
	std::string year = this->trim(v[0]);
	std::string month = this->trim(v[1]);
	std::string day = this->trim(v[2]);
	return (year + month + day);
}

void BitcoinExchange::setAllRates()
{
	std::ifstream	file("data.csv");
	std::string line;

	if (!file.is_open()) {
		std::cout << "Error opening file: data.csv " << std::endl;
		return ;
	}
	std::getline(file, line);	// Skip the first line as its a header line
	while (std::getline(file, line)) {
		std::vector<std::string> splitString = this->split(line, ',');
		if (splitString.size() == 2) {
			std::string date = this->trim(splitString[0]);
			if (isValidDate(date)) {
				std::string valueString = this->trim(splitString[1]);
				std::istringstream valueStream(valueString);
				std::string formattedDate = formatDateToYYYYMMDD(date);
				double	value;
				if (valueStream >> value) {
					this->rate.insert(std::make_pair(formattedDate, value));
				} else {
					std::cout << "Invalid value: " << splitString[1] << " on date: " << date << std::endl;
				}
			} else {
				std::cout << "Error: Invalid date as input => " << date << std::endl;
			}
		} else {
			std::cout << "Invalid line: " << line << std::endl;
		}
	}
	file.close();
}

void BitcoinExchange::run(const char *filename)
{
	setAllRates();
	int size = this->rate.size();
	if (size == 0) {
		std::cout << "Error: no rates found." << std::endl;
		return ;
	}
	this->iterateOverFile(filename);
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	int	year = 0, month = 0, day = 0;
	std::string	fulldate;

	if (date.length() != 10)
		return false;

	std::vector<std::string> v = this->split(date, '-');
	try {
		std::stringstream yearStream = std::stringstream(this->trim(v[0]));
		std::stringstream monthStream = std::stringstream(this->trim(v[1]));
		std::stringstream dayStream = std::stringstream(this->trim(v[2]));

		yearStream >> year;
		monthStream >> month;
		dayStream >> day;
	} catch (std::exception &e) {
		return false;
	}

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	int	monthSizes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear)
		monthSizes[1] = 29;
	if (day < 1 || day > monthSizes[month - 1])
		return false;
	if (month < 1 || month > 12)
		return false;
	if (year < 2009 || year > 2024)
		return false;
	
	return true;
}

void	BitcoinExchange::processLine(std::string date, double value)
{
	std::string formattedDate = formatDateToYYYYMMDD(date);
	std::map<std::string, double>::iterator iterator = this->rate.begin();
    std::map<std::string, double>::iterator end = this->rate.end();
	bool	found = false;

	for (; iterator != end; ++iterator) {
		if (iterator->first == formattedDate) {
			found = true;
			break ;
		}
	}
	if (found) {
		std::cout << date << " => " << value << " = " << value * iterator->second << std::endl;
	} else {
		std::map<std::string, double>::iterator lowerBound = this->rate.lower_bound(formattedDate);
		if (lowerBound != this->rate.end()) {
			if (lowerBound != rate.begin()) {
				std::map<std::string, double>::const_iterator previous = std::prev(lowerBound);
				std::cout << date << " => " << value << " = " << value * previous->second << std::endl;
			} else {
				std::cout << "Error: no rate found for date: " << date << std::endl;
			}
		} else {
			std::cout << "Error: no rate found for date: " << date << std::endl;
		}
		found = false;
	}
}

void    BitcoinExchange::iterateOverFile(std::string inputFile)
{
	std::ifstream	file(inputFile);
	std::string line;

	if (!file.is_open()) {
		std::cout << "Error opening file: " << inputFile << std::endl;
		return ;
	}
	std::getline(file, line);	// Skip the first line as its a header line
	while (std::getline(file, line)) {
		std::vector<std::string> splitString = this->split(line, '|');
		if (splitString.size() == 2) {
			std::string date = this->trim(splitString[0]);
			std::string valueString = this->trim(splitString[1]);
			std::istringstream valueStream(valueString);
			double	value;
			if (isValidDate(date)) {
				if (valueStream >> value) {
					if (value < 0.00 || value > 1000.00) {
						std::cout << "Error: ";
						if (value < 0.00)
							std::cout << "not a positive number." << std::endl;
						else if (value > 1000.00)
							std::cout << "too large a number." << std::endl;
					} else {
						processLine(date, value);
					}
				} else {
					std::cout << "Error: bad input => " << line << std::endl;
				}
			} else {
				std::cout << "Error: bad input => " << line << std::endl;
			}
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	file.close();
}
