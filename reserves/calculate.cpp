#include <iostream>

using namespace std;

int main()
{
    int inte1, inte2;
    float quot;

    cout << "input for the first integar: ____\b\b\b\b";
    cin >> inte1;
    cout << "input for the second integar: ____\b\b\b\b";
    cin >> inte2;

    quot = float(inte1) / float(inte2);

    cout << "Sum is " << inte1 + inte2 << endl;
    cout << "Difference is " << inte1 - inte2 << endl;
    cout << "Product is " << inte1 * inte2 << endl;
    cout << "Quotient is " << quot << endl;

    return 0;
}