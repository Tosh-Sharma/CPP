#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

/**
 * Use below line to test code with "sample.txt" file
 * and "Hello World" as input string to replace.
	make && ./output sample.txt "Hello World" "YO"
*/
/**
 * Get filename
 * Get s1 string
 * Get s2 string
 * Open File
 * Find occurence `_occ` of s1, note its position.
 * Create substring from start until _occ position.
 * Paste it into the new file.
 * Then paste s2 into the new file.
 * Then try to find another occurence after that
 * Repeat the same process again and again.
*/
void	write_to_file(std::string outputFileData, std::string outputFileName)
{
	std::ofstream outputFile(outputFileName);

	outputFile << outputFileData;
	outputFile.close();
}

std::string	find_and_replace(std::string inputFileData, std::string s1, std::string s2)
{
	std::string outputString;
	int	start = 0;
	int	position;
	int	length;
	int	x = 3;

	position = inputFileData.find(s1);
	while (position != -1)
	{
		length = position - start;
		if (length > 0)
			outputString += inputFileData.substr(start, length);
		outputString += s2;
		start = position + s1.length();
		position = inputFileData.find(s1, position + 1);
	}
	if (position == -1)
	{
		length = inputFileData.length() - (start + 1);
		outputString += inputFileData.substr(start, length);
	}
	return outputString;
}

std::string	read_from_input(std::string inputFileName)
{
	std::string		fileData;
	std::ifstream	inputFile(inputFileName);

	if (inputFile.is_open())
	{
		std::string	temp;
		while (std::getline(inputFile, temp))
		{
			fileData += temp;
			fileData+= '\n';
		}
		inputFile.close();
	}
	else
	{
		std::cout << "Error in opening file" << std::endl;
		return (NULL);
	}
	return (fileData);
}
 
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Need to pass 3 parameters" << std::endl;
		return (1);
	}
	else if (argc == 4)
	{
		std::string	inputFileName;
		std::string	s1;
		std::string	s2;
		std::string	outputFileName;
		std::string	inputFileData;
		std::string	outputFileData;

		inputFileName = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		outputFileName = inputFileName + ".replace";
		inputFileData = read_from_input(inputFileName);
		outputFileData = find_and_replace(inputFileData, s1, s2);
		write_to_file(outputFileData, outputFileName);
	}
	return (0);
}