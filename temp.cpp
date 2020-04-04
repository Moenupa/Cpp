
/*
for (int count = 1; count <= maxOddNums; count++) {
    if ((earlyStop = rand() / 100) < (curOddNum = count * 2 - 1)) {
        break;
    }
    else if (count == 1) {
        cout << curOddNum;
    }
    else {
        cout << ", " << curOddNum;
    }
}*/

int count = 1;
while ( (count<=maxOddNums) && ((rand() / 100)>=(count * 2 - 1)) ) {
    if ( count == 1 ) {
        cout << count * 2 - 1;
    } else {
        cout << ", " << count * 2 - 1;
    }
    cout++;
}