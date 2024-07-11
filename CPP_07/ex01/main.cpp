#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<int> iter[5];

void insertingInArrayofVector()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            iter[i].push_back(j);
        }
    }
}

void printElement()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Elements at index " << i << ": ";
        for (auto it = iter[i].begin(); it != iter[i].end(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }
}

void arrayOfVector(){
    insertingInArrayofVector();
    printElement(); 
}

int main(){
    arrayOfVector();
    return 0;
}