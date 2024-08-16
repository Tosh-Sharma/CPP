#include "whatever.hpp"

int main(void)
{
	    
        NumberClass a(2), b(4);

        std::cout << "PRE SWAP\n";
        std::cout << "Value of a is " << a << "\nValue of b is " << b << std::endl;
        swap(a, b);
        std::cout << "POST SWAP\n";
        std::cout << "Value of a is " << a << "\nValue of b is " << b << std::endl;

        std::cout << "\n\nMax out of A and B is " << max(a, b) << std::endl;
        std::cout << "Min out of A and B is " << min(a, b) << std::endl;

        std::cout << "PRE SWAP\n";
        int alpha = 2, beta = 4;
        std::cout << "\nValue of alpha is " << alpha << "\nValue of b is " << beta << std::endl;
        swap(alpha, beta);
        std::cout << "POST SWAP\n";
        std::cout << "\nValue of alpha is " << alpha << "\nValue of b is " << beta << std::endl;

        std::cout << "\n\nMax out of alpha and beta is " << max(alpha, beta) << std::endl;
        std::cout << "Min out of alpha and beta is " << min(alpha, beta) << std::endl;

        std::cout << "PRE SWAP\n";
        float alpha2 = 2.0f, beta2 = 4.0f;
        std::cout << "Value of alpha2 is " << alpha2 << "\nValue of beta2 is " << beta2 << std::endl;
        swap(alpha2, beta2);
        std::cout << "POST SWAP\n";
        std::cout << "Value of alpha2 is " << alpha2 << "\nValue of beta2 is " << beta2 << std::endl;
        std::cout << "\n\nMax out of alpha and beta is " << max(alpha2, beta2) << std::endl;
        std::cout << "Min out of alpha and beta is " << min(alpha2, beta2) << std::endl;

        return (0);
}

