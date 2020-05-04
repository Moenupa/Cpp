#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

int arrR[8] = {0, 0, 0, 0, 0, 0, 0, 0}, arrM[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, n = 0, flag = 0;
vector<vector<int>> instr;
map<string, int> proc = {{"halt",0},{"addq",1},{"subq",2},{"cmpq",3},{"je",4},{"jne",5},{"jg",6},{"jl",7},{"rrmovq",8},{"irmovq",9},{"rmmovq",10},{"mrmovq",11}};
map<int, int> label = {};

void printTable () {
    cout << "%%r0..7: ";                    // print arrR
    for (int i = 0; i < 8; i++) {
        cout << arrR[i];
        if (i!=7) cout << " ";
        else cout << endl;
    }
    cout << "M0..15: ";                     // print arrM
    for (int i = 0; i < 16; i++) {
        cout << arrM[i];
        if (i!=15) cout << " ";
        else cout << endl;
    }
}
vector<int> sep (string buf) {
    char *st1 = const_cast<char *>(buf.c_str());
    vector<int> temp_line;
    char *data[5];
    data[0] = strtok(st1, " \t\n:");
    for (int i = 1; i < 5; i++) {
        data[i] = strtok(NULL, " \t\n$%%(),");
    }
    if (strncmp(data[0], "L", 1)==0) { // if label detected
        label[stoi(strtok(data[0], " L:"))] = instr.size()-2;
        data[0] = data[1]; // data position changes
        for (int i = 1; i < 5; i++) {data[i] = strtok(data[i + 1], "r");}
    }
    temp_line.push_back(proc[data[0]]);
    for (int i = 1; i < 5; i++) {
        if (data[i]!=NULL) {
            temp_line.push_back(stoi(data[i]));
        }
    }
    return temp_line;
}
int main (int argc, const char *argv[]) {
    string buf;
    ifstream file;
    file.open(argv[1], ios::in);
    if (!file) {exit(1);}
    while (! file.eof()) {
        getline(file, buf, '\n');
        instr.push_back(sep(buf));
    }
    while (n++) {
        switch(instr[n][0]) {
            case 0:
                goto PRINT;
            case 1:
                arrR[instr[n][2]] += arrR[instr[n][1]];
                break;
            case 2:
                arrR[instr[n][2]] -= arrR[instr[n][1]];
                break;
            case 3:
                flag = arrR[instr[n][2]] - arrR[instr[n][1]];
                break;
            case 4:
                if (flag==0) {n = label[instr[n][1]];}
                break;
            case 5:
                if (flag!=0) {n = label[instr[n][1]];}
                break;
            case 6:
                if (flag>0) {n = label[instr[n][1]];}
                break;
            case 7:
                if (flag<0) {n = label[instr[n][1]];}
                break;
            case 8:
                arrR[instr[n][2]] = arrR[instr[n][1]];
                break;
            case 9:
                arrR[instr[n][2]] = instr[n][1];
                break;
            case 10:
                arrM[instr[n][2]+arrR[instr[n][3]]] = arrR[instr[n][1]];
                break;
            case 11:
                arrR[instr[n][3]] = arrM[instr[n][1]+arrR[instr[n][2]]];
                break;
        }
    }
    PRINT:
        printTable(); // format print arrR/arrM
        return 0;
}