#include <fstream> 
#include <iostream> 
#include <string> 
using namespace std; 

// void btcFunc(ifstream BTCFile){
//     ifstream inputB;
//     inputB.open('input.txt');
// };

int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr<<"Error Opening the file!"<<endl;
        return 1;
    }
    string line;
    cout << "File content: " << endl;
    while (getline(inputFile, line)) { 
        cout << line << endl;
    } 
    inputFile.close(); 
    return 0; 
    
}