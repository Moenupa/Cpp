# include <iostream>

using namespace std;

int main(){
    
    int a, c;
    float b;
	//init
    
    cout << "Input three integers: __ __ __\b\b\b\b\b\b\b\b";
    cin >> a >> b >> c;
	//get input
    
    cout << "Sum is " << a+b+c << endl;
    cout << "Average is " << (a+b+c)/3 << endl;
    cout << "Product is " << a*b*c << endl;
	//output
}
