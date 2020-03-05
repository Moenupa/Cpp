#include <iostream>

using namespace std;

int main(){

	int a, b, c, max, min;
	
	cout << "Input three integers: __ __ __\b\b\b\b\b\b\b\b";
	cin >> a >> b >> c;
	
	cout << "Sum is " << a+b+c << endl;
	cout << "Average is " << (a+b+c)/3 << endl;
	cout << "Product is " << a*b*c << endl;

    if (a > b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }

    if (c > max) {
        max = c;
    }
    else if (c < min) {
        min = c;
    }
    
    cout << "Smallest is " << min << endl;
    cout << "Largest is " << max << endl;
}