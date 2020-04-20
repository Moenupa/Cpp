#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

short arrR[8] = {0, 0, 0, 0, 0, 0, 0, 0}, arrM[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, n = 0;
vector<string> line, instr;
vector<string> split(string str, string pattern) {
    string::size_type pos;
    vector<string> result;
    str += pattern;
    for (int i = 0; i < str.size(); i++) {
        pos = str.find(pattern, i);
        if (pos < str.size()) {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}
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
void labelLine (const string label) {
    for (int i = 0; i < line.size(); i++) {
        if (line[i].compare(0,label.size(),label)==0) {
            n = i - 1;
            break;
        }
    }
}
int main (int argc, const char *argv[]) {
    short flag = 0;
    string buf;
    ifstream file;
    file.open(argv[1], ios::in);                     // load file
    if (!file) {exit(1);}
    while (! file.eof()) {
        getline(file, buf, '\n');                     // get instruction
        line.push_back(buf);
    }
    while (n++) {
        instr = split(line[n], " ");
        if (instr[0].compare(0,1,"L")==0) {     // if label detected // data position changes
            for (int i = 0; i < instr.size(); i++) {instr[i] = instr[i + 1];}
        }
        for (int i = 0; i < instr.size(); i++) {cout << setw(6) << instr[i];}
        cout << endl;
        if (instr[0].compare("halt") == 0) {
            break;
        } else if (instr[0].compare("addq") == 0) {
            arrR[stoi(instr[2])] += arrR[stoi(instr[1])];
        } else if (instr[0].compare("subq") == 0) {
            arrR[stoi(instr[2])] -= arrR[stoi(instr[1])];
        } else if (instr[0].compare("cmpq") == 0) {
            flag = arrR[stoi(instr[2])] - arrR[stoi(instr[1])];
        } else if (instr[0].compare("je") == 0) {
            if (flag == 0) {labelLine(instr[1]);}
        } else if (instr[0].compare("jne") == 0) {
            if (flag != 0) {labelLine(instr[1]);}
        } else if (instr[0].compare("jg") == 0) {
            if (flag > 0) {labelLine(instr[1]);}
        } else if (instr[0].compare("jl") == 0) {
            if (flag < 0) {labelLine(instr[1]);}
        } else if (instr[0].compare("rrmovq") == 0) {
            arrR[stoi(instr[2])] = arrR[stoi(instr[1])];
        } else if (instr[0].compare("irmovq") == 0) {
            arrR[stoi(instr[2])] = stoi(instr[1]);
        } else if (instr[0].compare("rmmovq") == 0) {
            arrM[stoi(instr[2])+arrR[stoi(instr[3])]] = arrR[stoi(instr[1])];
        } else if (instr[0].compare("mrmovq") == 0) {
            arrR[stoi(instr[3])] = arrM[stoi(instr[1])+arrR[stoi(instr[2])]];
        }                                   // process instructions
        Sleep(1);
    }
    printTable();                           // format print arrR/arrM
    file.close();
    return 0;
}