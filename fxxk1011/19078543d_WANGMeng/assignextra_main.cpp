/*
@author: WANG Meng
@USE: COMP1011 Assignment Extra
*/

#include <iostream>
#include "gameboard.h"
#include <windows.h>
#include <string>

void pve(Game currentgame, int difficulty);
void pvp(Game currentgame);
using namespace std;

int main ()
{
    #ifdef _WIN32
        SetConsoleOutputCP (65001);
        CONSOLE_FONT_INFOEX info = { 0 };
        info.cbSize = sizeof(info);
        info.dwFontSize.Y = 16;
        info.FontWeight = FW_NORMAL;
        wcscpy(info.FaceName, L"Consolas");
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
    #endif

    Game currentgame;
    string cmd;
    cout << "\tWelcome to the Tic-Tac-Toe game!\n\tIn this game, by , players try to win by placing O or X pieces on a 3x3 gameboard to get his own pieces in a line, which can be vertical, horizontal or diagnal with 3 same pieces\n\tFollow the guide to execute your desired instructions." << endl;

    SLET:                                                                   // select to start game or quit
        cout << "\
        ╔═════════════╤══════════════════╤══════════════════╗\n\
        ║    Index    │     0: Exit      │     1: Begin     ║\n\
        ╚═════════════╧══════════════════╧══════════════════╝" << endl;
        cin >> cmd;
        if (cmd.compare("1") == 0)
            goto MODE;
        else if (cmd.compare("0") == 0)
            return 0;
        else
        {
            cout << "Invalid input, please try again." << endl;
            goto SLET;
        }
    MODE:                                                                   // choose gamemode
        cout << "\
        ╔═════════════╤══════════════════╤══════════════════╗\n\
        ║    Index    │   1: Fight Bot   │    2: 1v1 PvP    ║\n\
        ╚═════════════╧══════════════════╧══════════════════╝" << endl;
        cin >> cmd;
        if (cmd.compare("1") == 0) goto DIFF;
        else if (cmd.compare("2") == 0) pvp(currentgame);
        else
        {
            cout << "Invalid Input, please try again." << endl;
            goto MODE;
        }
    DIFF:
        cout << "\
        ╔═════════════╤══════════════════╤══════════════════╗\n\
        ║    Index    │     1: Easy      │    2: Normal     ║\n\
        ╚═════════════╧══════════════════╧══════════════════╝" << endl;
        cin >> cmd;
        if (cmd.compare("1") == 0) pve(currentgame, 1);
        else if (cmd.compare("0") == 0) pve(currentgame, 2);
    LOOP:                                                                   // show winning side and loop back
        goto SLET;
}
