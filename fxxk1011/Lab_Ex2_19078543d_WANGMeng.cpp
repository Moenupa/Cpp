#include <iostream>
#include <string>
using namespace std;

char pattern, shape;
int base, num;
// init global variables

int main () {
    cout << "Please enter a symbol: ";
    cin >> pattern;                                         // get pattern character to be used
    cout << "Please enter width of the base: ";
    cin >> base;                                            // get base width (integer)
    cout << "Please enter the number of triangles: ";
    cin >> num;                                             // get number of triangles
    do {
        cout << "Please specify how to print the triangle: \n"
         << "'<' for right-angled triangle\n"
         << "'>' for left-angled triangle\n"
         << "'^' for two-equal-sided triangle\n> ";
        cin >> shape;                                       // get the triangle shape
    } while (shape != '<' && shape != '>' && shape != '^');
    if (shape == '^') {                                     // if equal-sided
        if (base > 0 && base % 2 == 1) {
            for (int i = 0; i <= (base-1)/2; i++) {
                string s((base-1)/2-i, ' '), p(2 * i + 1, pattern);
                for (int j = 0; j < num; j++) {
                    cout << s << p << s;                    // space - pattern - space
                }
                cout << endl;                               // after <num> times printint go to next line
            }
        } else {                                            // invalid input exit 1
            cout << "Error! Must be a positive odd integer.";
            exit(1);
        }
    } else {
        for (int i = 1; i <= base; i++) {
            string s(i, pattern), p(base-i, ' ');
            for (int j = 0; j < num; j++) {
                if (shape=='<') {                           // format output for right-angled
                    cout << s << p;
                } else {                                    // format output for left-angled
                    cout << p << s;
                }
            }
            cout << endl;                                   // same as above
        }
    }
    return 0;
}