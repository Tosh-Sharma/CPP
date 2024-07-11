#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

template <typename T>
void myFunction(T myname)
{
    auto x = myname;

    if (std::isnan(x))
    {
        cout << x << endl;

        cout << "char: " << char(x) << endl;

        // Converting nan to int
        int intValue = static_cast<int>(x);
        cout << "int: " << intValue << endl;

         // Converting nan to float
        float f1 = x;
        float floatValue = static_cast<float>(x);
        cout << "float: " << floatValue << endl;

        // Converting int to double
        double d1 = x;
        double d2 = static_cast<double>(x);
        std::cout << std::fixed << std::setprecision(2) << "double: " << d2 << std::endl;
    }
    else
    {
        string type = typeid(x).name();
        cout << type << endl;
        if (type == "i")
        {
            int intValue = x;

            cout << "char: " << char(intValue) << endl;

            cout << "int: " << intValue << endl;

            // Converting int to float
            float f1 = intValue;
            float floatValue = static_cast<float>(intValue);
            cout << "float: " << floatValue << endl;

            // Converting int to double
            double d1 = intValue;
            double d2 = static_cast<double>(intValue);
            std::cout << std::fixed << std::setprecision(2) << "double: " << d2 << std::endl;
        }
        else if (type == "f")
        {
            float floatValue = x;

            cout << "char: " << char(floatValue) << endl;

            // Converting float to int
            int intValue = static_cast<int>(round(floatValue));
            cout << "int: " << intValue << endl;

            std::cout << std::fixed << std::setprecision(2) << "float: " << floatValue << std::endl;

            // Converting float to double
            double d1 = floatValue;
            double d2 = static_cast<double>(floatValue);
            std::cout << std::fixed << std::setprecision(2) << "double: " << d2 << std::endl;
        }
        else if (type == "d")
        {
            double doubleValue = x;

            cout << "char: " << char(doubleValue) << endl;

            // Converting double to int
            int intValue = static_cast<int>(round(doubleValue));
            cout << "int: " << intValue << endl;

            // Converting double to float
            float f1 = doubleValue;
            float floatValue = static_cast<float>(doubleValue);
            cout << "float: " << floatValue << endl;

            cout << "double: " << doubleValue << endl;
        }
        else if (type == "c")
        {
            char charValue = x;

            cout << "char: " << charValue << endl;

            // Converting char to int
            int intValue = static_cast<int>(round(charValue));
            cout << "int: " << intValue << endl;

            // Converting char to float
            float f1 = charValue;
            float floatValue = static_cast<float>(charValue);
            cout << "float: " << floatValue << endl;

            // Converting char to double
            double d1 = charValue;
            double d2 = static_cast<double>(charValue);
            std::cout << std::fixed << std::setprecision(2) << "double: " << d2 << std::endl;
        }
    }
}

int main()
{
    myFunction(0);
    myFunction(std::nan(""));
    myFunction(42.0f);

    return 0;
}