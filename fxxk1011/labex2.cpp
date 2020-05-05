#include <iostream>
#include <string>
#include <vector>
using namespace std;

char pattern, shape;
int base, num;
// init global variables

int main () {
    cout << "Please enter a symbol: ";
    cin >> pattern;
    cout << "Please enter width of the base: ";
    cin >> base;
    cout << "Please enter the number of triangles: ";
    cin >> num;
    do {
        cout << "Please specify how to print the triangle: \n"
         << "'<' for right-angled triangle\n"
         << "'>' for left-angled triangle\n"
         << "'^' for two-equal-sided triangle\n> ";
        cin >> shape;
    } while (shape != '<' && shape != '>' && shape != '^');
    if (shape == '^') {
        if (base > 0 && base % 2 == 1) {
            for (int i = 0; i <= (base+1)/2; i++) {
                string s((base-1)/2-i, ' '), p(2 * i + 1, pattern);
                for (int j = 0; j < num; j++) {
                    cout << s << p << s;
                }
                cout << endl;
            }
        } else {
            cout << "Error! Must be a positive odd integer.";
            exit(1);
        }
    } else {
        for (int i = 0; i <= base; i++) {
            string s(i, pattern), p(base-i, ' ');
            for (int j = 0; j < num; j++) {
                if (shape=='<') {
                    cout << s << p;
                } else {
                    cout << p << s;
                }
            }
            cout << endl;
        }
    }
    return 0;
}