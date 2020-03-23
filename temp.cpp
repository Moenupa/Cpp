#include <iostream>

using namespace std;

int main () {
    const int SIZE = 5;

    int squares[SIZE] = {0, 1, 4, 9, 16};
    int lucky_numbers[SIZE];

    for (int i = 0; i < SIZE; i++) {
        lucky_numbers[i] = squares[i];
    }
}