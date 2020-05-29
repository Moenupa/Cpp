/*
@author: WANG Meng
@USE: COMP1011 Assignment 3
*/

#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

void pve(Game currentgame, int difficulty);
void pvp(Game currentgame);
const int LINES[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},                                        // vertical winning situations
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},                                        // horizontal winning situations
    {0, 4, 8}, {2, 4, 6}                                                    // diagnal winning situations
};
class Game
{
    public:
        int gameboard[9];                                                   // 1: player1, -1: player2, 0: vacant
        vector<int> status;                                                 // 8 ints, represent winning condition
        char piece[3];                                                      // 'O', 'X' or ' '
        int result;                                                         // 1: player1, -1: player2
        int process;                                                        // 0~9; number of steps taken

    public:
        void init()                                                         // initializing all variables
        {
            for (int i = 0; i < 9; i++)
                gameboard[i] = 0;

            piece[1] = ' ';
            srand(time(NULL));
            int dice = rand() % 2;                                          // random 'O' and 'X' for players
            if (dice == 0)
            {
                piece[0] = 'O';
                piece[2] = 'X';
            }
            else
            {
                piece[0] = 'X';
                piece[2] = 'O';
            }

            process = 0;
            result = 0;
        }
        void cal_status()                                                   // calculate the winning possibility
        {
            status.clear();
            int sum = 0;
            for (int i = 0; i < 8; i++)                                     // -3~3 to represent possibility to win
            {
                sum = 0;
                for (int j = 0; j < 3; j++) sum += gameboard[LINES[i][j]];
                if (abs(sum)==3) result = sum / 3;                          // reached 3 or -3 meaning win
                status.push_back(sum);
            }
        }
        void print_board(char mode)                                         // format printout of the board
        {
            switch (mode)
            {
                case 'I':
                    cout << "╔═══╤═══╤═══╗\n"
                         << "║ 1 │ 2 │ 3 ║\n"
                         << "╟───┼───┼───╢\n"
                         << "║ 4 │ 5 │ 6 ║\n"
                         << "╟───┼───┼───╢\n"
                         << "║ 7 │ 8 │ 9 ║\n"
                         << "╚═══╧═══╧═══╝" << endl;
                    break;
                case 'P':
                    cout << "╔═══╤═══╤═══╗\n"
                         << "║ " << piece[gameboard[0]+1] << " │ " << piece[gameboard[1]+1] << " │ " << piece[gameboard[2]+1] << " ║\n"
                         << "╟───┼───┼───╢\n"
                         << "║ " << piece[gameboard[3]+1] << " │ " << piece[gameboard[4]+1] << " │ " << piece[gameboard[5]+1] << " ║\n"
                         << "╟───┼───┼───╢\n"
                         << "║ " << piece[gameboard[6]+1] << " │ " << piece[gameboard[7]+1] << " │ " << piece[gameboard[8]+1] << " ║\n"
                         << "╚═══╧═══╧═══╝" << endl;
                    break;
            }
        }
        void get_input()                                                    // get input from the user
        {
            int playerpos;
            process += 1;
            while (true)
            {
                cout << piece[(process % 2) * 2] << "'s turn.\nEnter desired position: ";
                cin.clear();
                cin.ignore();
                cin >> playerpos;
                if (playerpos > 0 && playerpos < 10)
                {
                    if (gameboard[playerpos - 1] == 0)
                    {
                        gameboard[playerpos - 1] = (process % 2) * 2 - 1;
                        break;
                    }
                    else cout << "Space already occupied! Please enter again." << endl;
                }
                else cout << "Invalid position index. Please try again." << endl;
            }
        }
        void bot_play()                                                     // bot simulator
        {
            process += 1;
            cal_status();
            int bot_pos = rand() % (9 - process), vacantpos = 0, strategy = 0, dangerline = 0;
            for (int i = 0; i < 8; i++)
            {
                if (status[i] == -2)                                        // two bot pieces in a line
                {
                    dangerline = i;
                    strategy = -1;
                    break;
                }
                dangerline = (status[i] > strategy) ? i : dangerline;
                strategy = (status[i] > strategy) ? status[i] : strategy;
            }
            if (strategy == -1)                                             // attack
            {
                if (gameboard[LINES[dangerline][1]] == 0)
                    gameboard[LINES[dangerline][1]] = (process % 2) * 2 - 1;
                else if (gameboard[LINES[dangerline][0]] == 0)
                    gameboard[LINES[dangerline][0]] = (process % 2) * 2 - 1;
                else if (gameboard[LINES[dangerline][2]] == 0)
                    gameboard[LINES[dangerline][2]] = (process % 2) * 2 - 1;
            }
            else if (strategy == 0)                                         // random
            {
                for (int i = 0; i < 9; i++)
                {
                    if (gameboard[i] == 0) vacantpos += 1;
                    if (bot_pos == vacantpos) gameboard[i] = (process % 2) * 2 - 1;
                }
            }
            else                                                            // defend
            {
                if (gameboard[LINES[dangerline][1]] == 0)
                    gameboard[LINES[dangerline][1]] = (process % 2) * 2 - 1;
                else if (gameboard[LINES[dangerline][0]] == 0)
                    gameboard[LINES[dangerline][0]] = (process % 2) * 2 - 1;
                else if (gameboard[LINES[dangerline][2]] == 0)
                    gameboard[LINES[dangerline][2]] = (process % 2) * 2 - 1;
                else
                {
                    for (int i = 0; i < 9; i++)
                    {
                        if (gameboard[i] == 0) vacantpos += 1;
                        if (bot_pos == vacantpos) gameboard[i] = (process % 2) * 2 - 1;
                    }
                }
            }
        }
        void show_win()                                                     // show winning side/draw
        {
            if (result == 0) cout << "Game ends in a TIE." << endl;
            else cout << piece[result + 1] << " Wins!" << endl;
        }
};

#endif //GAMEBOARD_H_INCLUDED