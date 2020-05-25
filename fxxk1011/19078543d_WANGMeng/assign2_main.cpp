#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int LINES[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};
class Game
{
    public:
        int gameboard[9];
        vector<int> status;
        char piece[3];
        int result;
        int process;

    public:
        void init()
        {
            for (int i = 0; i < 9; i++)
                gameboard[i] = 0;

            piece[1] = ' ';
            srand(time(NULL));
            int dice = rand() % 2;
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
        void cal_state()
        {
            status.clear();
            int sum = 0;
            for (int i = 0; i < 8; i++)
            {
                sum = 0;
                for (int j = 0; j < 3; j++) sum += gameboard[LINES[i][j]];
                if (abs(sum)==3) result = sum / 3;
                status.push_back(sum);
            }
        }
        void printboard(char mode)
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
        void get_input()
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
        void botplay()
        {
            process += 1;
            cal_state();
            int bot_pos = rand() % (9 - process), vacantpos = 0, strategy = 0, dangerline = 0;
            for (int i = 0; i < 8; i++)
            {
                if (status[i] == -2)
                {
                    dangerline = i;
                    strategy = -1;
                    break;
                }
                dangerline = (status[i] > strategy) ? i : dangerline;
                strategy = (status[i] > strategy) ? status[i] : strategy;
            }

            if (strategy == -1)
            {
                if (gameboard[LINES[dangerline][1]] == 0)
                {
                    gameboard[LINES[dangerline][1]] = (process % 2) * 2 - 1;
                }
                else if (gameboard[LINES[dangerline][0]] == 0)
                {
                    gameboard[LINES[dangerline][0]] = (process % 2) * 2 - 1;
                }
                else if (gameboard[LINES[dangerline][2]] == 0)
                {
                    gameboard[LINES[dangerline][2]] = (process % 2) * 2 - 1;
                }
            }
            else if (strategy == 0)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (gameboard[i] == 0) vacantpos += 1;
                    if (bot_pos == vacantpos) gameboard[i] = (process % 2) * 2 - 1;
                }
            }
            else
            {
                if (gameboard[LINES[dangerline][1]] == 0)
                {
                    gameboard[LINES[dangerline][1]] = (process % 2) * 2 - 1;
                }
                else if (gameboard[LINES[dangerline][0]] == 0)
                {
                    gameboard[LINES[dangerline][0]] = (process % 2) * 2 - 1;
                }
                else if (gameboard[LINES[dangerline][2]] == 0)
                {
                    gameboard[LINES[dangerline][2]] = (process % 2) * 2 - 1;
                }
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
        void show_win()
        {
            cout << piece[result + 1] << " Wins!" << endl;
        }
};
Game currentgame;
// global variables and types

void pvp();
void pve();
// declearing functions

int main ()
{
    string cmd;
    cout << "\tWelcome to the Tic-Tac-Toe game!\n\tIn this game, by , players try to win by placing O or X pieces on a 3x3 gameboard to get his own pieces in a line, which can be vertical, horizontal or diagnal with 3 same pieces\n\tFollow the guide to execute your desired instructions."<< endl;
    SLET:
        cout << "\
        ╔═════════════╤══════════════════╤══════════════════╗\n\
        ║    Index    │     0: Exit      │     1: Begin     ║\n\
        ╚═════════════╧══════════════════╧══════════════════╝" << endl;
        cin >> cmd;
        if (cmd.compare("1") == 0)
        {
            goto MODE;
        }
        else if (cmd.compare("0") == 0)
        {
            return 0;
        }
        else
        {
            cout << "Invalid input, please try again." << endl;
            goto SLET;
        }
    MODE:
        cout << "\
        ╔═════════════╤══════════════════╤══════════════════╗\n\
        ║    Index    │   1: Fight Bot   │    2: 1v1 PvP    ║\n\
        ╚═════════════╧══════════════════╧══════════════════╝" << endl;
        cin >> cmd;
        if (cmd.compare("1") == 0) pve();
        else if (cmd.compare("2") == 0) pvp();
        else
        {
            cout << "Invalid Input, please try again." << endl;
            goto MODE;
        }
    WIN:
        currentgame.printboard('P');
        currentgame.show_win();
        goto SLET;
}
void pve()
{
    currentgame.init();
    currentgame.printboard('I');
    cout << "Computer choose " << currentgame.piece[0] << "." << endl;
    while (currentgame.process != 9)
    {
        if (currentgame.process % 2 == 0)
        {
            currentgame.printboard('P');
            currentgame.get_input();
        }
        else
        {
            currentgame.botplay();
        }
        currentgame.cal_state();
        if (abs(currentgame.result) == 1) return;
    }
}
void pvp()
{
    currentgame.init();
    currentgame.printboard('I');
    while (currentgame.process != 9)
    {
        currentgame.printboard('P');
        currentgame.get_input();
        currentgame.cal_state();
        if (abs(currentgame.result) == 1) return;
    }
}