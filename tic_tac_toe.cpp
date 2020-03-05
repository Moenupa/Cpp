/*
limitations:
1. inconvenient input for the user
    - user have to use 1-9 to represent the whole board;
2. do not provide win-and-stop detection
    - once a side wins, do not instantly stop the subsequent input (which is no longer meaningful).
features:
1. use an array of 9 integers from [1,-1,0] to represent player1, player2 and vacant board position;
2. interpret the representation method in 1 to the readable X\O board format;
3. use 1-9 input detect and position-filled detect to prevent invalid-input bugs;
4. modulized functions.
*/

#include <iostream>
using namespace std;
bool check(int choice[9],int i) {                       // check if the cell is already filled
    bool flag = true;
    for (int iter=0;iter<i;iter++) {
        if (choice[iter] == choice[i]) {flag = false;}
    }
    return flag;
}
void show(int board[9],char piece1, char piece2) {      // interpret the board to human-readable format
    char boardox[9];
    for (int iter=0; iter<9; iter++) {
        switch(board[iter]){
            case 0:
                boardox[iter] = ' ';
                break;
            case 1:
                boardox[iter] = piece1;
                break;
            case -1:
                boardox[iter] = piece2;
                break;
        }
    }
    for (int i=0; i<9; i++) {
        if (i%3 == 0) {
            cout << "\t " << boardox[i] << " | ";
        } else if (i%3 == 1) {
            cout << boardox[i] << " | ";
        } else if (i == 8) {
            cout << boardox[i] << " \n";
        } else {
            cout << boardox[i] << "\n\t--- --- ---\n";
        }
    }
}
void limit (char piece1, char piece2, int i) {          // limit the input to O\X
    char input, correct;
    if (i%2 == 0) {correct = piece1;}
    else {correct = piece2;}
    if (i != 0){
        while (true){
            cout << "Please enter " << correct << ": _\b";
            cin >> input;
            if (input != correct) {
                cout << "Error: it is the " << correct << "'s turn." << endl;
                continue;
            } else {
                break;
            }
        }
    }
}
int main(void) {
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, choice[9];
    char piece1 = ' ', piece2= ' ';
    cout << "Here is what the game board looks like with the IDs of each cell:\
    \n\t 1 | 2 | 3 \n\t--- --- ---\n\t 4 | 5 | 6 \n\t--- --- ---\n\t 7 | 8 | 9 \n";
    while(true) {                                       // piece1 and piece2 to be O\X and X\O
        switch(piece1) {
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
    }                                                   // initialize: board, choice, player1's piece, player2's piece

    for (int i=0; i<9; i++) {
        limit(piece1, piece2, i);                       // limit input to one in X\O

        cout << "Please enter the cell ID for your move: _\b";
        cin >> choice[i];                               // store in array choice with sequence

        if (choice[i]<1 || choice[i]>9) {
            cout << "Warning: invalid cell ID." << endl;
            i -= 1;
        } else if ( check(choice, i) ) {
            if (i%2 == 0) {board[choice[i]-1] = 1;}     // player1 assigned 1
            else {board[choice[i]-1] = -1;}             // player2 assigned -1
            show(board, piece1, piece2);                // interpret and print out the board
            cout << "This is step " << i+1 << ", there are " << 9-i-1 << " more steps." << endl;
        } else {                                          // if cell filled, show a warning and loop back
            cout << "Warning: cell already filled!" << endl;
            i -= 1;
        }
    }
}