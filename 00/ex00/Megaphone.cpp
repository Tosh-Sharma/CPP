#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::toupper;

int	main(int argc, char **argv)
{
	string	str;
	char	c;

	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (unsigned long j = 0; j < str.length(); j++)
			{
				c = (char)toupper(str[j]);
				cout << c;
			}
			cout << " ";
		}
	}
	return (0);
}