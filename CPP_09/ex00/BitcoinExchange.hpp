#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	rate;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void run(const char *filename);

		std::vector<std::string> split(const std::string &s, char delimiter);
		std::string trim(const std::string &s);

		std::string	formatDateToYYYYMMDD(std::string date);
		bool		isValidDate(std::string date);

		void	setAllRates();
		void	printRates() const;
		void	iterateOverFile(std::string file);
		void	processLine(std::string date, double value);
};
