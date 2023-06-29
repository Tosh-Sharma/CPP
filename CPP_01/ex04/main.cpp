#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using	std::string;
using	std::getline;
using	std::cin;
using	std::ifstream;
using	std::ofstream;
using	std::cout;
using	std::endl;

/**
 * Use below line to test code using sample.txt 
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
void	write_to_file(string outputFileData, string outputFileName)
{
	ofstream outputFile(outputFileName);

	outputFile << outputFileData;
	outputFile.close();
}

string	find_and_replace(string inputFileData, string s1, string s2)
{
	string outputString;
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

string	read_from_input(string inputFileName)
{
	string		fileData;
	ifstream	inputFile(inputFileName);

	if (inputFile.is_open())
	{
		string	temp;
		while (getline(inputFile, temp))
		{
			fileData += temp;
			fileData+= '\n';
		}
		inputFile.close();
	}
	else
	{
		cout << "Error in opening file" << endl;
		return (NULL);
	}
	return (fileData);
}
 
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Need to pass 3 parameters" << endl;
		return (1);
	}
	else if (argc == 4)
	{
		string	inputFileName;
		string	s1;
		string	s2;
		string	outputFileName;
		string	inputFileData;
		string	outputFileData;

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