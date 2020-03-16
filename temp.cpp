#include <iostream>
#include <stdio.h>

using namespace std;
void printReverse(const char *str) {
    if (!*str) {
        return;
    }
    printReverse(str+1);
    putchar(*str);
}

int main() {
    char str[100];
    cout << "Input string: ";
    while (cin >> str) {
        char ch = getchar();
        if (ch != '\n') {
            break;
        }
    }
    cout << str;
    printReverse(str);
}

