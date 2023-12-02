//
// Created by Marc on 02/12/2023.
//

#include "function_main.h"
#include <stdio.h>
operationInfo giveInfoLine (char* line){
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


    return lineInfo;

}




