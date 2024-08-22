#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        try
        {
    		BitcoinExchange	sample;
			sample.run(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else
        std::cout << "Error: Invalid number of input arguments."
			<< " Format is ./bitcoin [filename]" << std::endl;
	return (0);
}
