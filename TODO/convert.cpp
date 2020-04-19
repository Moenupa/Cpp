/*
Converting a sequence of values

What unit do you want to convert from? #cm
What unit do you want to convert to? #in
Enter values, terminated by 0: #30
## 30 cm = 11.81 in
Enter values, terminated by 0: #100
## 100 cm = 39.37 in
Enter values, terminated by 0: #0
What unit do you want to convert from?

From unit (in, ft, mi, mm, cm, m, km, oz, lb, g, kg, tsp, tbsp, pint, gal): #cm
To unit: #in
*/

#include <iostream>
using namespace std;

void select () {
    cout << "Select between:"
         << "\n\tLength: in, ft, mi, mm, cm, m,  km"
         << "\n\tWeight: oz, lb, g, kg, tsp, tbsp, pint, gal";

}

void weight () {

}

int main () {
    cout << "What unit do you want to convert from?";

    char u1, u2;
}