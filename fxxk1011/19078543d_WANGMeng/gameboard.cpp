/*
@author: WANG Meng
@USE: COMP1011 Assignment 2
*/

#include <iostream>
#include "gameboard.h"
using namespace std;
void pve(Game currentgame, int difficulty)                                  // run the game in PVE mode
{
    currentgame.init();
    currentgame.print_board('I');
    cout << "Computer choose " << currentgame.piece[0] << "." << endl;
    if (difficulty == 1)
    {
        while (currentgame.process != 9)
        {
            if (currentgame.process % 2 == 0)
            {
                currentgame.print_board('P');
                currentgame.get_input();
            }
            else
            {
                currentgame.bot_play();
            }
            currentgame.cal_status();
            if (abs(currentgame.result) == 1) return;
        }
    }
    else if (difficulty == 2)
    {

    }
}
void pvp(Game currentgame)                                                  // run the game in PVP mode
{
    currentgame.init();
    currentgame.print_board('I');
    while (currentgame.process != 9)
    {
        currentgame.print_board('P');
        currentgame.get_input();
        currentgame.cal_status();
        if (abs(currentgame.result) == 1) return;
    }
}