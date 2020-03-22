#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    char str[100];
    cout << "Input string: ";
    cin >> str;
    printReverse(str);
}

void printReverse(const char *str) {
    if (!*str) {
        return;
    }
    printReverse(str+1);
    putchar(*str);
}