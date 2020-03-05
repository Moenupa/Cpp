#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// solve the quadratic equation, output the root(s) if any, and no real root if none.

int main(){
    double a, b, c, dis;//the discriminant of the quadratic equation

    //gathering a, b, c
    cout << "Format : a x^2 + b x + c = 0" << endl;
    cout << "Please enter a: _\b";
    cin >> a;
    cout << "Please enter b: _\b";
    cin >> b;
    cout << "Please enter c: _\b";
    cin >> c;

    //judge if b^2-4ac>0
    dis = pow(b, 2) - 4*a*c;


    if (dis < 0){
        cout << "No real root" << endl;
    }
    else {
        cout.setf(ios::showpoint);
        if (dis == 0){
            double sol = -b / (2*a);
            cout << setprecision(3) << "Repeated root: x = " << sol;
        }
        else {
            double sol1 = (-b+sqrt(dis)) / (2*a), sol2 = (-b-sqrt(dis)) / (2*a);
            cout << setprecision(3) << "Two real roots: x = " << sol1 << " or " << sol2 << endl;
        }
    }
}