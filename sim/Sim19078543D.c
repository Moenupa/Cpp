#include <stdio.h>
#include <string.h>
#include <stdlib.h>
short arrR[8] = {0, 0, 0, 0, 0, 0, 0, 0}, arrM[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
FILE *fp, *fp1;
char buf[100], *proc = NULL, *data[4] = {NULL, NULL, NULL, NULL};
void labelLine (const char *label) {
    rewind(fp);
    rewind(fp1);                            // reset fp/alternative fp
    int count = 0;
    char buf1[100];
    do {
        fgets(buf1, 100, fp1);
        proc = strtok(buf1, " \n:,");
        count++;
    } while (strcmp(proc, label) != 0);
    for (int i = 0; i < count-1; i++) {     // set fp to the labelLine
        fgets(buf, 100, fp);
    }
}
void printTable () {
    printf("%%r0..7: ");                    // print arrR
    for (int i = 0; i < 8; i++) {
        if (i!=7) printf("%d ", arrR[i]);
        else printf("%d\n", arrR[i]);
    }
    printf("M0..15: ");                     // print arrM
    for (int i = 0; i < 16; i++) {
        if (i!=15) printf("%d ", arrM[i]);
        else printf("%d\n", arrM[i]);
    }
}
int main (int argc, const char *argv[]) {
    short flag=0;
    fp = fopen(argv[1], "r");               // load file
    fp1 = fopen(argv[1], "r");
    if (fp==NULL)
        return 1;                           // file loading error
    while (1) {
        fgets(buf, 100, fp);
        proc = strtok(buf, " \t\n:");       // get instruction
        data[0] = strtok(NULL, " \t\n$%%(),");
        data[1] = strtok(NULL, " \n$%%(),");
        data[2] = strtok(NULL, " \n$%%(),");
        data[3] = strtok(NULL, " \n$%%(),");// get data
        if (strncmp(proc, "L", 1)==0) {     // if label detected
            proc = data[0];                 // data position changes
            for (int i = 0; i < 3; i++) {data[i] = data[i + 1];}
        }
        for (int i = 0; i < 4; i++) {data[i] = strtok(data[i], "r");}
        if (strcmp(proc, "halt") == 0) {
            break;
        } else if (strcmp(proc, "addq") == 0) {
            arrR[atoi(data[1])] += arrR[atoi(data[0])];
        } else if (strcmp(proc, "subq") == 0) {
            arrR[atoi(data[1])] -= arrR[atoi(data[0])];
        } else if (strcmp(proc, "cmpq") == 0) {
            flag = arrR[atoi(data[1])] - arrR[atoi(data[0])];
        } else if (strcmp(proc, "je") == 0) {
            if (flag==0) {labelLine(data[0]);}
        } else if (strcmp(proc, "jne") == 0) {
            if (flag != 0) {labelLine(data[0]);}
        } else if (strcmp(proc, "jg") == 0) {
            if (flag>0) {labelLine(data[0]);}
        } else if (strcmp(proc, "jl") == 0) {
            if (flag<0) {labelLine(data[0]);}
        } else if (strcmp(proc, "rrmovq") == 0) {
            arrR[atoi(data[1])] = arrR[atoi(data[0])];
        } else if (strcmp(proc, "irmovq") == 0) {
            arrR[atoi(data[1])] = atoi(data[0]);
        } else if (strcmp(proc, "rmmovq") == 0) {
            arrM[atoi(data[1])+arrR[atoi(data[2])]] = arrR[atoi(data[0])];
        } else if (strcmp(proc, "mrmovq") == 0) {
            arrR[atoi(data[2])] = arrM[atoi(data[0])+arrR[atoi(data[1])]];
        }                                   // process instructions
    }
    printTable();                           // format print arrR/arrM
    fclose(fp);
    fclose(fp1);
    return 0;
}