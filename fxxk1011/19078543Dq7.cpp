#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int main ()
{
    srand(time(NULL));
    int dice[2], stats[6][6];
    memset(stats, 0, sizeof(stats));
    for (int i = 0; i < 36000; i++)
    {
        dice[0] = rand() % 6;
        dice[1] = rand() % 6;
        stats[dice[0]][dice[1]] += 1;
    }
    cout << "     1     2     3     4     5     6  \n"
         << "    ----------------------------------" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "|";
        for (int j = 0; j < 6; j++)
        {
            cout << setw(6) << stats[i][j];
        }
        cout << endl;
    }
    cout << "    ----------------------------------" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "|";
        for (int j = 0; j < 6; j++)
        {
            cout << setw(6) << stats[i][j] - 1000;
        }
        cout << endl;
    }
}