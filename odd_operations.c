//
// Created by yael1 on 04/12/2023.
//

#include "odd_operations.h"
#include <stdio.h>

//LDA operation : LDA <reg1> <reg2>/<var>/<const> - OP Code 00000
//Load register reg1 with the contents of either the contents of reg2, or the memory var or a constant
//const. Memory regions loads (load into a variable, for instance) are NOT ALLOWED
void LDA(operationInfo lineInfo, int registers[], int variables[]){
    //lineInfo.value1 is the register to be loaded
    printf("Register number %d\n", lineInfo.value1);


    // if type2 is a register
    if (lineInfo.type2==1){
        printf("We load the value of the register number %d\n", lineInfo.value2);
        registers[lineInfo.value1] = registers[lineInfo.value2];
    }

        // if type2 is a variable
    else if (lineInfo.type2==2){
        printf("We load the value of the variable number %d\n", lineInfo.value2);
        registers[lineInfo.value1] = variables[lineInfo.value2];
    }

        // if type2 is a constant
    else if (lineInfo.type2==3){
        printf("We load a constant with the value %d\n", lineInfo.value2);
        registers[lineInfo.value1] = lineInfo.value2;
    }
}

//PUSH <reg>/<var>/<const> - OP Code 00010
//Push to the top of the stack the contents of reg or var or a constant const
void PUSH(operationInfo lineInfo, int registers[], int variables[], int stack[], int *sp){
    // if type1 is a register
    if (lineInfo.type1==1){
        printf("We push the value of the register n %d\n", lineInfo.value1);
        stack[*sp] = registers[lineInfo.value1];
        *sp = *sp + 1;
    }

    // if type1 is a variable
    else if (lineInfo.type1==2){
        printf("We push the value of the variable n %d\n", lineInfo.value1);
        stack[*sp] = variables[lineInfo.value1];
        *sp = *sp + 1;
    }

    // if type1 is a constant
    else if (lineInfo.type1==3){
        printf("We push a constant with the value %d\n", lineInfo.value1);
        stack[*sp] = (lineInfo.value1);
        *sp = *sp + 1;
    }
}
