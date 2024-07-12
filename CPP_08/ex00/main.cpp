#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template <typename T>

void easyfind(T a[], int b)
{
    for (int i = 0; i < 5; i++)
    {
        a[i] = a[i];
        // int it = find(a[i]begin(), a[i].end(), b);
        // if (it != a[i].end())
        // {
        //     cout << "The first occurence of Second Parameter on First Parameter : " << b << " is at index: " << it - a[i].begin() << endl;
        // }
        // else
        // {
        //     cout << "Element Not Found" << endl;
        // }
        auto it = std::find(std::to_string(a[0]).begin(), std::to_string(a[4]).end(), b);
        if (it != std::to_string(a[4]).end())
        {
            cout << "The first occurence of Second Parameter on First Parameter : " << b << " is at index: " << it - std::to_string(a[0]).begin() << endl;
        }
        else
        {
            cout << "Element Not Found" << endl;
        }
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b = 1;
    easyfind<int> (a, b);
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    return 1;
}