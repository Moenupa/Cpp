#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    int array_size = 0, data[10]={0}, insert, temp;
    double output;
    while (true) {                                      // loop getting input while input is invalid or not created
        cout << "Input integers(end by 0): ";
        cin >> temp;                                    // getting intput
        if (temp == 999) break;                         // input 999 to break and find median
        else {
            data[array_size] = temp;                    // store in array if not 0
            array_size++;
        }
        cout << array_size << endl;
    }
    cout << "Data items in original order\n";
    for (int i = 0; i < array_size; i++) {
        cout << setw(4) << data[i];                     // print original order
    }
    for (int next = 1; next < array_size; next++) {     // sorting
        insert = data[next];
        int moveItem = next;
        while ((moveItem>0) && (data[moveItem-1] < insert)) {
            data[moveItem] = data[moveItem - 1];
            moveItem--;
        }
        data[moveItem] = insert;
    }
    if (array_size % 2 == 0) {
        output = (data[array_size / 2] + data[array_size / 2 - 1]) / 2.0;
    } else {
        output = data[(array_size - 1) / 2];
    }                                                   // find the median
    cout.flags(ios::fixed);
    cout << "\nThe Median of the sequence is " << setprecision(1) << output << endl;
                                                        // print the median
    return 0;
}