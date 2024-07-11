#include <fstream>
#include <iostream>
#include <string.h>

template <class T>

class Array{
    public:
    T x, y, a;
    T size;
    Array(){
        T a[] = {};
    };
    Array(unsigned int n, T cx, T cy, T csize){
        x = cx;
        y = cy;
        size = csize;
        T *a = new T[size];
    }
    Array(const Array& other){
        x = other.x;
        y = other.y;
        size = other.size;
    };
    void add(){
        std::cout << x + y << std::endl;
    }
    void display(){
        std::cout << a << std::endl;
    }
    void sizee(){
        std::cout << "Length of Array is : " << size << std::endl;
    }
};
int main(){
    Array<int> s1;
    Array<int> s2(-1, 3, 3, 2);
    Array<int> s3 = s2;
    Array<int> obj[] = {s2,s3};
    for (int i = 0; i < 2; i++)
    {
        obj[i].add();
    }
    int b[] = {};
    s1.display();
    s2.display();
    s2.sizee();
    return 0;
}