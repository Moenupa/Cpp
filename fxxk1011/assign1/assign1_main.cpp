/*
WARNING: run this program directly(exe) or by cmd\powershell\bash using "./" command
do NOT run in INTEGRATED terminals (system("cls") will cause problem)
@file assign1_main.cpp
@author Wang Meng
@date 2020-04-30
@version 2.1
@debug through gcc8.1.0 with c++14(default)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

const vector<string> INFO = {
    "-I",
    "╔══════════╤════════════════════════════════╤═══════╗",
    "║ ItemCode │              Name              │ Price ║",
    "╟──────────┴────────────────────────────────┴───────╢",
    "║ Section A: Sandwiches                             ║",
    "╟──────────┬────────────────────────────────┬───────╢",
    "║    A1    │ Cheese veggie sandwich         │  $30  ║",
    "║    A2    │ Salmon & cheese sandwich       │  $34  ║",
    "║    A3    │ Chicken Caesar Sandwich        │  $32  ║",
    "╟──────────┴────────────────────────────────┴───────╢",
    "║ Section B: Quiche, Pie & Bagel with Cream Cheese  ║",
    "╟──────────┬────────────────────────────────┬───────╢",
    "║    B1    │ (Quebec homemade) Quiche       │  $28  ║",
    "║    B2    │ Bagel with Cream Cheese        │  $20  ║",
    "║    B3    │ (East Village Chicken) Pie     │  $28  ║",
    "╟──────────┴────────────────────────────────┴───────╢",
    "║ Section C: Coffee, Tea, Hot Chocolate, Milk&Juice ║",
    "╟──────────┬────────────────────────────────┬───────╢",
    "║    C1    │ Coffee                         │  $36  ║",
    "║    C2    │ Green Tea                      │  $28  ║",
    "║    C3    │ Hot Chocolate                  │  $28  ║",
    "║    C4    │ Milk                           │  $26  ║",
    "║    C5    │ Juice                          │  $26  ║",
    "╟──────────┴────────────────────────────────┴───────╢",
    "║ Section S: Set Meals                              ║",
    "╟──────────┬────────────────────────────────┬───────╢",
    "║    S1    │ Refreshing Breakfast           │  $48  ║",
    "║          │     + Coffee                   │       ║",
    "║          │     + Bagel with cream cheese  │       ║",
    "║    S2    │ Best Value Breakfast           │  $60  ║",
    "║          │     + Milk                     │       ║",
    "║          │     + Chicken Caesar Sandwich  │       ║",
    "║          │     + Bagel with Cream Cheese  │       ║",
    "║    S3    │ Veggie Lunch                   │  $50  ║",
    "║          │     + Juice                    │       ║",
    "║          │     + Cheese veggie sandwich   │       ║",
    "║    S4    │ Power Lunch                    │  $90  ║",
    "║          │     + Juice                    │       ║",
    "║          │     + Coffee                   │       ║",
    "║          │     + Salmon & cheese sandwich │       ║",
    "║          │     + Pie                      │       ║",
    "║    S5    │ Afternoon Tea Set              │  $50  ║",
    "║          │     + Coffee or Tea            │       ║",
    "║          │     + Quiche or Pie            │       ║",
    "╚══════════╧════════════════════════════════╧═══════╝",
    "-I", "-E",
    " ________         _______  ________      ________  ________  ________ _______      ",    "|\\_____  \\       /  ___  \\|\\_____  \\    |\\   ____\\|\\   __  \\|\\  _____\\\\  ___ \\     ",    " \\|___/  /|____ /__/|_/  /\\|____|\\ /_   \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\__/\\ \\   __/|    ",    "     /  / /\\____\\__|//  / /     \\|\\  \\   \\ \\  \\    \\ \\   __  \\ \\   __\\\\ \\  \\_|/__  ",    "    /  / /\\|____|   /  /_/__   __\\_\\  \\   \\ \\  \\____\\ \\  \\ \\  \\ \\  \\_| \\ \\  \\_|\\ \\ ",    "   /__/ /          |\\________\\|\\_______\\   \\ \\_______\\ \\__\\ \\__\\ \\__\\   \\ \\_______\\",    "   |__|/            \\|_______|\\|_______|    \\|_______|\\|__|\\|__|\\|__|    \\|_______|",
    "╔═════════════╤══════════════════╤══════════════════╗",
    "║   Welcome   │  0: Exit System  │  1: Start Order  ║",
    "╚═════════════╧══════════════════╧══════════════════╝",
    "-E", "-O",
    "╔═════════════╤══════════════════╤══════════════════╗",
    "║    Order    │   0: Check out   │   1: Continue    ║",
    "╚═════════════╧══════════════════╧══════════════════╝",
    "-O", "-R",
    "╔═══════════════════════════════════════════════════╗",
    "║                  Checkout Review                  ║",
    "╟──────────┬────────────────────────────────┬───────╢",
    "║ ItemCode │              Name              │ Price ║",
    "╟──────────┼────────────────────────────────┼───────╢",
    "-R", "-S",
    "╚═══════════════════════════════════════════════════╝",
    "-S", "-P",
    "╔═════════════╤══════════════════╤══════════════════╗",
    "║   Payment   │    0: Cancel     │    1: Confirm    ║",
    "╚═════════════╧══════════════════╧══════════════════╝", "-P"};
map<string, int> price = {{"A1", 30}, {"A2", 34}, {"A3", 32}, {"B1", 28}, {"B2", 20}, {"B3", 28}, {"C1", 36}, {"C2", 28}, {"C3", 28}, {"C4", 26}, {"C5", 26}, {"S1", 48}, {"S2", 60}, {"S3", 50}, {"S4", 90}, {"S5", 50}};
// init preset resources

class NewOrder {
    public:
        string ois;                                                                             // customer ois
        map<string, int> order;                                                                 // order details
        float total;                                                                            // order price
    public:
        void init(string oisin)                                                                 // initiate
        {
            order = {{"A1", 0}, {"A2", 0}, {"A3", 0}, {"B1", 0}, {"B2", 0}, {"B3", 0}, {"C1", 0}, {"C2", 0}, {"C3", 0}, {"C4", 0}, {"C5", 0}, {"S1", 0}, {"S2", 0}, {"S3", 0}, {"S4", 0}, {"S5", 0}};
            total = 0;
            ois = oisin;
        }
        void mergeToSet()                                                                       // merge seperate order to a set
        {
            while (order["C1"]!=0 && order["B2"]!=0) {
                --order["C1"];
                --order["B2"];
                ++order["S1"];
            } while (order["C4"]!=0 && order["A3"]!=0 && order["B2"]!=0) {
                --order["C4"];
                --order["A3"];
                --order["B2"];
                ++order["S2"];
            } while (order["C5"]!=0 && order["A1"]!=0) {
                --order["C5"];
                --order["A1"];
                ++order["S3"];
            } while (order["C5"]!=0 && order["C1"]!=0 && order["A2"]!=0 && order["B3"]!=0) {
                --order["C5"];
                --order["C1"];
                --order["A2"];
                --order["B3"];
                ++order["S4"];
            } while ((order["C1"]!=0||order["C2"]!=0) && (order["B1"]!=0||order["B3"]!=0)) {
                if (order["C1"]!=0) {
                    --order["C1"];
                } else if (order["C2"]!=0) {
                    --order["C2"];
                }
                if (order["B1"]!=0) {
                    --order["B1"];
                } else if (order["B3"]!=0) {
                    --order["B3"];
                }
                ++order["S5"];
            }
        }
        float cal_total()                                                                       // calculate total order price
        {

            total = 0;
            for (auto iter = order.begin(); iter != order.end(); iter++)
            { // iterate through all the ITEM
                total += price[iter->first] * iter->second;
            }
            return total;
        }
};
vector<NewOrder> orders = {};                                                                   // all orders will be saved to this vector
// NOTE: in real application this should be put into a file for transmission
string buf;                                                                                     // handle input and prevent excecptions
// init global class type and variables

void printCmd(string token);                                                                    // print Command details
void printOrd(string token, int repeatTimes);                                                   // print order details
void clearTerminal();                                                                           // clear the terminal
// declear used functions

int main () {
    #ifdef _WIN32
        SetConsoleOutputCP (65001);                                                             // ensure utf-8 character display normally
        CONSOLE_FONT_INFOEX info = { 0 };
        info.cbSize = sizeof(info);
        info.dwFontSize.Y = 16;                                                                 // leave X as zero
        info.FontWeight = FW_NORMAL;
        wcscpy(info.FaceName, L"Consolas");                                                     // set a font that is adequate for display
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
    #endif
    // ensure utf-8 character support

    int cur_cus;
    string cmd, tempOis, tempOrd = "";
    // local variabel to indicate current customer handle input

    SYSIN:                                                                                      // exit: exit or order
        clearTerminal();
        printCmd("-E");
        cout << "┃ Enter command index ┃ _\b";
        cin >> cmd;
        if (cmd.compare("0")==0)                                                                // 0 exit
        {
            cout << "Exit System." << endl;
            return 0;
        }
        else if (cmd.compare("1")==0)                                                           // 1 start order
        {
            clearTerminal();
            goto OISIN;
        }
        else                                                                                    // else loop back
        {
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto SYSIN;
        }
    OISIN:                                                                                      // ois: input ois and check legal
        cout << "┃ Personalize your Pick-Up Code (e.g.<oh my god>) ┃\n┠ ________\b\b\b\b\b\b\b\b";
        cin.clear();
        cin.sync();
        getline(cin, tempOis);
        cur_cus = orders.size();
        for (int i = 0; i < cur_cus; i++)                                                       // check if ois occupied
        {
            if (tempOis.compare(orders[i].ois)==0)
            {
                cout << "Pick-Up Code already exists, try another one." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                clearTerminal();
                goto OISIN;
            }
        }
        orders.push_back(NewOrder());
        orders[cur_cus].init(tempOis);                                                          // create new NewOrder and set its ois
        clearTerminal();
    ORDIN:                                                                                      // order: ask for item code
        printCmd("-I");
        cout << "┃ Enter Item Code ┃ __\b\b";
        cin >> tempOrd;
        if (tempOrd.compare("0") == 0)
        {
            cout << "┃ NULL INPUT ┃" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
        else if (orders[cur_cus].order.find(tempOrd) != orders[cur_cus].order.end())                 // if valid add the food by 1
        {
            orders[cur_cus].order[tempOrd] += 1;
        }
        else                                                                                    // else loop back order
        {
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto ORDIN;
        }
    ORDLOOP:                                                                                    // orderloop: continue or stop ordering
        printCmd("-O");
        cout << "┃ Enter Order Command Index ┃  _\b";
        cin >> cmd;
        if (cmd.compare("0") == 0)                                                              // stop: save the order, then return to sysinput
        {
            clearTerminal();
            orders[cur_cus].mergeToSet();
            printCmd("-R");
            for (auto iter = orders[cur_cus].order.begin(); iter != orders[cur_cus].order.end(); iter++)
            {                                                                                   // go through all ITEM
                printOrd(iter->first,iter->second);
            }
            cout << "╟──────────┴────────────────────────────────┴───────╢" << endl;
            cout << "║ PickUpCode: " << setw(37) << orders[cur_cus].ois << " ║"<< endl;
            orders[cur_cus].cal_total();
            if (orders[cur_cus].total > 100)
            {
                cout << "║ Total before Discount: " << setw(16) << "$" << setw(10) << fixed << setprecision(2) << orders[cur_cus].total / 1.0 << " ║" << endl;
                cout << "║ Discount of 5%: " << setw(23) << "-$" << setw(10) << fixed << setprecision(2) << orders[cur_cus].total / 1.0 * 0.05 << " ║" << endl;
                orders[cur_cus].total *= 0.95;
            }
            cout << "║ Total: " << setw(32) << "$" << setw(10)<< fixed << setprecision(2) << orders[cur_cus].total/1.0 << " ║" << endl;
            printCmd("-S");
            goto PAYIN;
        }
        else if (cmd.compare("1") == 0)                                                         // make order, then setback to ordinput
        {
            clearTerminal();
            goto ORDIN;
        }
        else                                                                                    // invalid input - loop back to ordinput
        {
            clearTerminal();
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto ORDLOOP;
        }
    PAYIN:                                                                                      // pay: confirm order and pay (payment skipped)
        printCmd("-P");
        cout << "┃ Enter Payment Command Index ┃  _\b";
        cin >> cmd;
        if (cmd.compare("0") == 0)                                                              // if cancel 0, then return to sysin
        {
            orders.pop_back();
            cout << "┃ Payment Canceled ┃" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto SYSIN;
        }
        else if (cmd.compare("1") == 0)                                                         // if confirmed 1, then return to sysin
        {
            cout << "┃ Payment Confirmed ┃" << endl;
            this_thread::sleep_for(chrono::seconds(4));                                         // sleep for 4 seconds
            goto SYSIN;
        }
        else
        {
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto PAYIN;
        }
}
void printCmd(string token)                                                                     // print Command details
{
    bool flag = false;
    for (int i = 0; i < INFO.size(); i++)                                                       // loop through INFO
    {
        buf = INFO[i];
        if (buf.compare(0,2,token)==0) {flag = !flag;}                                          // if token detected, start or end printing
        else if (flag) {cout << buf << endl;}
    }
}
void printOrd(string token, int repeatTimes)                                                    // print order details
{
    if (repeatTimes!=0)
    {
        for (int i = 0; i < INFO.size(); i++)
        {
            buf = INFO[i];
            if (buf.find(token, 4) != string::npos)
            {
                for (int j = 0; j < repeatTimes; j++) {cout << buf << endl;}
            }
        }
    }
}
void clearTerminal ()                                                                           // clear the terminal
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}