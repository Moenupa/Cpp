#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
	double x = pow(1.05, 10);
	unsigned salary;
	//init
	
	cout << "What is your salary?\n$";
	cin >> salary;
	//get user input
	
	cout << "After 10 years, your salary is: " << x * salary;
	//output calculated salary
}