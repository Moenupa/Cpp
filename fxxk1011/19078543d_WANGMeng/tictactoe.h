/*
@author: WANG Meng
@USE: COMP1011 Assignment Extra
*/

#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED

#include <iostream>
#include <vector>

class Game
{
    public:
        int gameboard[9];                                                   // 1: player1, -1: player2, 0: vacant
        std::vector<int> status;                                            // 8 ints, represent winning condition
        char piece[3];                                                      // 'O', 'X' or ' '
        int result;                                                         // 1: player1, -1: player2
        int process;                                                        // 0~9; number of steps taken
        const int LINES[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},                                // vertical winning situations
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},                                // horizontal winning situations
            {0, 4, 8}, {2, 4, 6}                                            // diagnal winning situations
        };                                                                  // winning lines

    public:
        void init();                                                        // initializing all variables
        void cal_status();                                                  // calculate the winning possibility
        void print_board(char mode);                                        // format printout of the board
        void get_input();                                                   // get input from the user
        void bot_random();                                                  // bot simulator
        void bot_play();                                                    // bot simulator
        void show_win();                                                    // show winning side/draw
};

void pve(Game currentgame, int difficulty);
void pvp(Game currentgame);

#endif                                                                      //GAMEBOARD_H_INCLUDED