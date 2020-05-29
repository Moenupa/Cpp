/*
@author: WANG Meng
@USE: COMP1011 Assignment 3
*/

#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

const int LINES[8][3];// vertical/horizontal/diagnal winning situations

class Game
{
    public:
        // vaiables

    public:
        void init()                                                         // initializing all variables
        {
            cout << "Initializing the game board..." << endl;
        }
        void cal_status()                                                   // calculate the winning possibility
        {
            cout << "Calculating candidate lines in the gameboard..." << endl;
        }
        void print_board(char mode)                                         // format printout of the board
        {
            cout << "printint out the board situation..." << endl;
        }
        void get_input()                                                    // get input from the user
        {
            cout << "getting your input..." << endl;
        }
        void bot_play()                                                     // bot simulator
        {
            cout << "Bot playing..." << endl;
        }
        void show_win()                                                     // show winning side/draw
        {
            cout << "showing who wins or showing a tie..." << endl;
        }
};

#endif