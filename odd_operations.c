//
// Created by yael1 on 04/12/2023.
//

#include "odd_operations.h"
#include <stdio.h>

//LDA operation : LDA <reg1> <reg2>/<var>/<const> - OP Code 00000
//Load register reg1 with the contents of either the contents of reg2, or the memory var or a constant
//const. Memory regions loads (load into a variable, for instance) are NOT ALLOWED
void LDA(operationInfo lineInfo, int registers[], char variables[]){
    //lineInfo.value1 is the register to be loaded
    printf("LDA\n");
    printf("register n° %d\n", lineInfo.value1);


    // if type2 is a register
    if (lineInfo.type2==1){
        printf("we load register n° %d\n", lineInfo.value2);
        registers[lineInfo.value1]=registers[lineInfo.value2];
        printf("register n° %d have the value: \n", lineInfo.value1, registers[lineInfo.value1]);
    }

    // if type2 is a variable
    else if (lineInfo.type2==2){
        printf("we load variable n° %d\n", lineInfo.value2);
        registers[lineInfo.value1]=variables[lineInfo.value2];
        printf("register n° %d have the value: \n", lineInfo.value1, registers[lineInfo.value1]);
    }

    // if type2 is a constant
    else if (lineInfo.type2==3){
        printf("we load constant with the value %d\n", lineInfo.value2);
        registers[lineInfo.value1]=lineInfo.value2;
        printf("register n° %d have the value: \n", lineInfo.value1, registers[lineInfo.value1]);
    }
}
