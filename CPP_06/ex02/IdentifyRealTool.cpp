#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Base{
    public:
    int var_base;
    void generate()
    {
        cout << "Displaying Base Class" << " variable var_base: "<< var_base << endl;
    }
};

class A: public Base{
    // public:
    // int var_a;
    // void generate()
    // {
    //     cout << "Displaying Base Class" << " variable var_base: "<< var_base << endl;
    //     cout << "Displaying A Class" << " variable var_a " << var_a << endl;
    // }
};

class B : public Base{
    // public:
    // int var_b;
    // void generate()
    // {
    //     cout << "Displaying Base Class" << " variable var_base: "<< var_base << endl;
    //     cout << "Displaying B Class" << " variable var_b " << var_b << endl;
    // }
};

class C : public Base{
    // public:
    // int var_c;
    // void generate()
    // {
    //     cout << "Displaying Base Class" << " variable var_base: "<< var_base << endl;
    //     cout << "Displaying C Class" << " variable var_c " << var_c << endl;
    // }
};

int main(){
    Base* base_class_pointer;
    Base obj_base;
    A obj_a;
    base_class_pointer = &obj_a;
    std::cout << typeid(&obj_a).name() << endl;
    std::cout << typeid(Base*).name() << endl;
    std::cout << typeid(base_class_pointer).name() << endl;
    base_class_pointer->var_base = 41;
    base_class_pointer->generate();
    return 0;
}