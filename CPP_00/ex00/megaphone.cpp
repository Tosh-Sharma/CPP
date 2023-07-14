#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	str;
	char		c;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (unsigned long j = 0; j < str.length(); j++)
			{
				c = (char)std::toupper(str[j]);
				std::cout << c;
			}
		}
	}
	return (0);
}