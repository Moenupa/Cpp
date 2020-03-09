// Demonstrating switch control structure
// Uppercase and lowercase input are also considered

#include <iostream>

using namespace std;

int main() {
	
	int mark;
	
	char grade;
	
	cout << "Please enter your mark: __\b\b";
	cin >> mark;
	
	if (mark >= 90 && mark <= 100) {
		grade = 'A';
	}
	else if (mark >= 70 && mark <= 89) {
		grade = 'B';
	}
	else if (mark >= 50 && mark <= 69) {
		grade = 'C';
	}
	else if (mark >= 40 && mark <= 49) {
		grade = 'D';
	}
	else if (mark >= 0 && mark <= 39) {
		grade = 'F';
	}
    cout << "Your grade is " << grade << endl;
	switch (grade){
		case 'a':
		case 'A':
			cout << "Excellent!" << endl;
			break;
		case 'b':
		case 'B':
			cout << "Good!" << endl;
			break;
		case 'c':
		case 'C':
			cout << "OK!" << endl;
			break;
		case 'd':
		case 'D':
			cout << "Marginal" << endl;
			break;
		case 'f':
		case 'F':
			cout << "Failed!" << endl;
			break;
		default:
			cout << "Input is wrong" << endl;
	}
	return 0;
}