/* this is file Year X.cpp
You are working with a coding partner. He is halfway finished with this program.
He also left many comments for you to complete the program.
Here is what we know:
1. The program is called Year X. This year is Year X.
2. This program gets input of month and day and then prints the weekday of the given input.
3. This program first prints out the case for April 15.
4. It is known that January 1st of Year X is Monday.
5. It is known that Febuary of the Year X has 28 days.
6. All variables are already defined, so you cannot add more variables except the loop control variables.
7. You cannot change the existing lines of codes or comments. You are allowed to add codes and add comments.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    // init
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May","Jun","Jul", "Aug", "Sep","Oct", "Nov", "Dec"};
    string weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    const int daysPerWeek = 7;
    const int monthPerYear = 12;

    // Year X
    string dayOne = "Mon";
    int dayOneNum = 1;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //section 1: take care the case of April 15
    int theDay = 15, theMonth = 4, days, theWeekDay;
    days = monthDays[1-1] + monthDays[2-1] + monthDays[3-1] + theDay;
    theWeekDay = days % daysPerWeek;
    cout << "Apr 15 is ";
    switch (theWeekDay) {
    // task 1: please print the corresponding weekday using the weekdays array from Monday to Sunday
        case 0:
            cout << weekdays[6] << endl;
            // 0-1 is invalid so 6 as the Sun
            break;
        default:
            cout << weekdays[theWeekDay - 1] << endl;
            // index start with 0 so have to -1
    }
    // the end of task 1

    // Section 2: take care of the user input month and day
    string inMonth;
    int inDay;

    // prompt the user for input month and day
    // task 2: check the input month is legitimate
    // please provide the code for this part
    // input
    INMONTH:cout << "Please input the Month of your choice:" << endl;
    cin >> inMonth;
    for (int iter = 0; iter < monthPerYear; iter++) {
        if (inMonth.compare(0,3,months[iter]) ==0 ) break;
        // compare the first 3 characters between input and default months
        // if yes go to the next section i.e. enter the day
        else if (iter == monthPerYear - 1) {
        // end when reaching all months and still get no match
            cout << "Invalid Month input" << endl;
            goto INMONTH;
            // loop
        }
    }
    // the end of task2

    // task 3: check the input day is legitimate
    // please provide the code for this part
    INDAY:cout << "Please input the day of your choice" << endl;
    cin >> inDay;
    for (int month = 0; month < monthPerYear; month++) {
        if (inMonth.compare(0,3,months[month])==0) {
        // finds the index of the month
            if (inDay <= monthDays[month] && inDay >= 1) break;
            // check the day using the month index
            else {
                cout << "Invalid day input" << endl;
                goto INDAY;
                // if invalid, prompt and loop
            }
        }
    }
    // the end of task 3

    cout << inMonth << " " << inDay << " is ";
    // task 4: please find out the weekday and print it out
    // follow the sample output in the April 15 example.
    // print out the input month and day is which weekday
    for (int month = 0; month < monthPerYear; month++) {
        if (inMonth.compare(0,3,months[month])==0) {
        // finds the index of the month
            for (int iter_month = 0; iter_month < month; iter_month++) {
                inDay += monthDays[iter_month];
                // cumulate the total days
            }
            inDay %= daysPerWeek;
            // mod 7 to get weekday
            switch (inDay) {
                // same as above
                case 0:
                    cout << weekdays[6] << endl;
                    break;
                default:
                    cout << weekdays[inDay - 1] << endl;
            }
            break;
        }
    }
    // the end of task 4

    return 0;
}