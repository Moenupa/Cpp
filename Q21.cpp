#include <iostream>
using namespace std;
bool all_the_same (double x, double y, double z) {
    bool flag = ((x==y) && (y==z));             // true if x==y==z
    return flag;
}
int main () {
    double x, y, z;                             // init double
    x = y = z = 3.14159;                        // set x y z to the same value
    if (all_the_same(x,y,z))                    // prompt whether xyz all the same
        cout << "x, y, z are all the same" << endl;
    else
        cout << "x, y, z are not all the same" << endl;
    return 0;
}