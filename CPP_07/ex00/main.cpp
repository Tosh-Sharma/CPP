#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int a = 2;
    int b = 4;

    ::swap(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "min(a, b): " << ::min(a,b) << std::endl;
    std::cout << "max(a, b): " << ::max(a,b) << std::endl;
    return 0;
}