#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1;                            // string variables, on <string>
    char str2[]="Hello World";              // char variables
    int integer;                            // int variables
    int integers[10];                       // array of ints
    // variables should be announced before output or other uses
    
    cout << "This is a string variable" << str1 << endl;
    cout << "This is a string variable" << str2 << endl;
    cout << "This is an integer variable" << integer << endl;
    // print the variables

    for (auto &x : integers) {
        cout << x << " ";
    }

}