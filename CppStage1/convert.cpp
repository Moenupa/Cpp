#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main () {
    string str1;
    stringstream str2;
    int int1 = 25;
    str2 << int1;
    str2 >> str1;
    cout << str1 << endl;
    return 0;
}

void int_to_string (void) {
    string str1;
    stringstream str2;
    int int1 = 25;


}


// stoi in _#include <cstdio>
void bin_dec (void) {
    string bin1 = "10101", dec1 = "25";
    int bin2, dec2;

    bin2 = stoi(dec1,0,10);
    dec2 = stoi(bin1,0,2);
    cout << "bin to dec: " << bin1 << "to" << dec2 << endl;
    cout << "dec to bin: " << dec1 << "to" << bin2 << endl;

}