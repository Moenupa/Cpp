
#include <iostream>

using namespace std;

int main()
{
    int integer1;
    int integer2;
    int sum;
    char name[10];

    cout << "Input your name: here\b\b\b\b";
    cin >> name;
    cout << name << ", welcome to calculator!\n";

    cout << "\tEnter first integer: ";
    cin >> integer1

    cout << "\tEnter second integer: ";
    cin >> integer2;

    sum = integer1 + integer2;
    cout << "Sum is " << sum << endl;
    return 0;
}