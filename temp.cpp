#include <iostream>
using namespace std;
int main ()
{
    int arr[] = {-1, 0, 1};
    for (auto &x : arr)
        cout << (x+1) / 2 << endl;
    return 0;
}