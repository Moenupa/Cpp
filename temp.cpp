#include <iostream>

using namespace std;

int main(){
    char piece1 = ' ', piece2 = ' ';
    while(true){
        switch(piece1){
        case 'O':
            piece2 = 'X';
            break;
        case 'X':
            piece2 = 'O';
            break;
        default:
            cout << "Please enter 'O' or 'X': _\b";
            cin >> piece1;
            continue;
        }
        break;
    }
    cout << "The end";
    return 0;
}