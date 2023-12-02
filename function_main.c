//
// Created by Marc on 02/12/2023.
//

#include "function_main.h"
#include "stdio.h"
operationInfo giveInfoLine (char* line){
    int cpt= 0;
    operationInfo lineInfo;
    lineInfo.line = line;

    char ope[5] = "";
    for (int i = 0; i < 5; i++) {
        ope[i] = line[i];
    }
    //Convert ope which is binary to decimal
    int decimal = 0;
    for (int i = 0; i < 5; i++) {
        decimal += (ope[i] - '0') * (1 << (4 - i));
    }
    lineInfo.operation = decimal;
    cpt+=5;

    char type1[2]="";
    type1[0]=line[cpt];
    type1[1]=line[cpt+1];
    //Convert type1 which is binary to decimal
    if (type1[0]=='0' && type1[1]=='1'){
        lineInfo.type1=1;
    }
    else if (type1[0]=='1' && type1[1]=='0'){
        lineInfo.type1=2;
    }
    else if (type1[0]=='1' && type1[1]=='1'){
        lineInfo.type1=3;
    }
    cpt+=2;
    if (lineInfo.type1==1){
        lineInfo.value1=type_register(line, cpt);
        cpt+=2;
    }
    else if (lineInfo.type1==2){
        lineInfo.value1=type_variable(line, cpt);
        cpt+=5;
    }
    else if (lineInfo.type1==3){
        lineInfo.value1=type_constant(line, cpt);
        cpt+=8;
    }

    char type2[2]="";
    type2[0]=line[cpt];
    type2[1]=line[cpt+1];
    //Convert type2 which is binary to decimal
    if (type2[0]=='0' && type2[1]=='1'){
        lineInfo.type2=1;
    }
    else if (type2[0]=='1' && type2[1]=='0'){
        lineInfo.type2=2;
    }
    else if (type2[0]=='1' && type2[1]=='1'){
        lineInfo.type2=3;
    }
    cpt+=2;
    if (lineInfo.type2==1){
        lineInfo.value2=type_register(line, cpt);
        cpt+=2;
    }
    else if (lineInfo.type2==2){
        lineInfo.value2=type_variable(line, cpt);
        cpt+=5;
    }
    else if (lineInfo.type2==3){
        lineInfo.value2=type_constant(line, cpt);
        cpt+=8;
    }
    char label[19]="";
    int i=0;
    while (cpt!=32){
        label[i] = line[cpt];
        i++;
        cpt++;
    }
    lineInfo.label=convert_dec(label, i);


    return lineInfo;

}

int type_register(char* line, int cpt){
    char reg[2] = "";
    for (int i = 0; i < 2; i++) {
        reg[i] = line[cpt+i];
    }
    //Convert reg which is binary to decimal
    int decimal = 0;
    decimal= convert_dec(reg, 2);
    return decimal;
}

int type_variable(char* line, int cpt){
    char var[5] = "";
    for (int i = 0; i < 5; i++) {
        var[i] = line[cpt+i];
    }
    //Convert var which is binary to decimal
    int decimal = 0;
    decimal= convert_dec(var, 5);
    return decimal;
}

int type_constant(char* line, int cpt){
    char cons[8] = "";
    for (int i = 0; i < 8; i++) {
        cons[i] = line[cpt+i];
    }
    //Convert cons which is binary to decimal
    int decimal = 0;
    decimal= convert_dec(cons, 8);
    return decimal;
}


int convert_dec(char* tab, int size){
    int decimal = 0;
    for (int i = 0; i < size; i++) {
        decimal += (tab[i] - '0') * (1 << (size - i -1));
    }
    return decimal;
}


