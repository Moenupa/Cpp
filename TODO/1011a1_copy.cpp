// WARNING: run this program directly(exe) or by cmd\powershell\bash using "./" command
// do NOT run in vscode internal terminal (clear terminal will cause problem)
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
    " ________         _______  ________      ________  ________  ________ _______      ",
    "|\\_____  \\       /  ___  \\|\\_____  \\    |\\   ____\\|\\   __  \\|\\  _____\\\\  ___ \\     ",
    " \\|___/  /|____ /__/|_/  /\\|____|\\ /_   \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\__/\\ \\   __/|    ",
    "     /  / /\\____\\__|//  / /     \\|\\  \\   \\ \\  \\    \\ \\   __  \\ \\   __\\\\ \\  \\_|/__  ",
    "    /  / /\\|____|   /  /_/__   __\\_\\  \\   \\ \\  \\____\\ \\  \\ \\  \\ \\  \\_| \\ \\  \\_|\\ \\ ",
    "   /__/ /          |\\________\\|\\_______\\   \\ \\_______\\ \\__\\ \\__\\ \\__\\   \\ \\_______\\",
    "   |__|/            \\|_______|\\|_______|    \\|_______|\\|__|\\|__|\\|__|    \\|_______|",
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

class Customer {
    public:
        string ois;
        map<string, int> order;
        int total;
    public:
        void init(string oisin) {
            order = {{"A1", 0}, {"A2", 0}, {"A3", 0}, {"B1", 0}, {"B2", 0}, {"B3", 0}, {"C1", 0}, {"C2", 0}, {"C3", 0}, {"C4", 0}, {"C5", 0}, {"S1", 0}, {"S2", 0}, {"S3", 0}, {"S4", 0}, {"S5", 0}};
            total = 0;
            ois = oisin;
        }
        void check_set() {
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
        int cal_total() {
            for (auto iter = order.begin(); iter != order.end(); iter++) { // 遍历所有ITEM
                total += price[iter->first] * iter->second;
            }
            return total;
        }
};
vector<Customer> orders = {};
string buf;

void get_info(string key);
void get_item(string code, int repeat);
int main () {
    #ifdef _WIN32
        SetConsoleOutputCP (65001); // make sure utf-8 character display normally
        CONSOLE_FONT_INFOEX info = { 0 };
        info.cbSize = sizeof(info);
        info.dwFontSize.Y = 16; // leave X as zero
        info.FontWeight = FW_NORMAL;
        wcscpy(info.FaceName, L"Consolas"); // set a font that is adequate for display
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
    #endif
    int cur_cus;
    string cmd, tempOis, tempOrd = "";
    SYSIN: //
        cout << "\033[2J\033[1;1H";
        get_info("-E"); // 退出或进入点单提示窗
        cout << "┃ Enter command index ┃ _\b";
        cin >> cmd;
        if (cmd.compare("0")==0) { // 0 退出
            cout << "Exit System." << endl;
            return 0;
        } else if (cmd.compare("1")==0) { // 1 点单
            cout << "\033[2J\033[1;1H";
            goto OISIN;
        } else { // 否则重复
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto SYSIN;
        }
    OISIN: // 输入OIS
        cout << "┃ Personalize your Pick-Up Code (e.g.<oh my god>) ┃\n┠ ________\b\b\b\b\b\b\b\b";
        cin.clear();
        cin.sync();
        getline(cin, tempOis);
        cur_cus = orders.size();
        for (int i = 0; i < cur_cus; i++) {  // 检查重复
            if (tempOis.compare(orders[i].ois)==0) {
                cout << "Pick-Up Code already exists, try another one." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << "\033[2J\033[1;1H";
                goto OISIN;
            }
        }
        orders.push_back(Customer());
        orders[cur_cus].init(tempOis); // 生成新对象并传入ois
        cout << "\033[2J\033[1;1H";
    ORDIN:
        get_info("-I");
        cout << "┃ Enter Item Code ┃ __\b\b";
        cin >> tempOrd;
        if (orders[cur_cus].order.find(tempOrd) != orders[cur_cus].order.end()) {
            orders[cur_cus].order[tempOrd] += 1;
        } else {
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto ORDIN;
        }
    ORDLOOP:
        get_info("-O");
        cout << "┃ Enter Order Command Index ┃ _\b";
        cin >> cmd;
        if (cmd.compare("0") == 0) { // stop: save orderings, then return to sysinput
            cout << "\033[2J\033[1;1H";
            orders[cur_cus].check_set();
            get_info("-R");
            for (auto iter = orders[cur_cus].order.begin(); iter != orders[cur_cus].order.end(); iter++) { // 遍历所有ITEM
                get_item(iter->first,iter->second);
            }
            cout << "╟──────────┴────────────────────────────────┴───────╢" << endl;
            cout << "║ PickUpCode:   " << setw(35) << orders[cur_cus].ois << " ║"<< endl;
            cout << "║ Total:  $" << setw(40) << fixed << setprecision(2) << orders[cur_cus].cal_total()/1.0 << " ║"<< endl;
            get_info("-S");
            goto PAYIN;
        } else if (cmd.compare("1") == 0) {   // make order, then setback to ordinput
            cout << "\033[2J\033[1;1H";
            goto ORDIN;
        } else {                    // invalid input - loop back to ordinput
            cout << "\033[2J\033[1;1H";
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto ORDLOOP;
        }
    PAYIN:
        get_info("-P");
        cout << "┃ Enter Payment Command Index ┃ _\b";
        cin >> cmd;
        if (cmd.compare("0") == 0) {
            orders.pop_back();
            cout << "┃ Payment Canceled ┃" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto SYSIN;
        } else if (cmd.compare("1") == 0) {
            cout << "┃ Payment Confirmed ┃\n┃ Thanks for coming to 7-23 Cafe. See you next time. ┃" << endl;
            this_thread::sleep_for(chrono::seconds(4));
            goto SYSIN;
        } else {
            cout << "┃ INVALID INPUT ┃ Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            goto PAYIN;
        }
}
void get_info(string key) {
    bool flag = false;
    for (int i = 0; i < INFO.size(); i++) {
        buf = INFO[i];
        if (buf.compare(0,2,key)==0) {
            flag = !flag;
        } else if (flag) {
            cout << buf << endl;
        }
    }
}
void get_item(string code, int repeat) {
    if (repeat!=0) {
        for (int i = 0; i < INFO.size(); i++) {
            buf = INFO[i];
            if (buf.find(code, 4) != string::npos) {
                for (int j = 0; j < repeat; j++) {
                    cout << buf << endl;
                }
            }
        }
    }
}