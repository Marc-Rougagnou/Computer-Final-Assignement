//
// Created by yael1 on 04/12/2023.
//

#include "odd_operations.h"
#include <stdio.h>
#include <math.h>

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


//AND <reg1> <reg2>/<var>/<const> - OP Code 00011
//Performs a logical AND operation between reg1 and a register reg2, a variable var or a constant
//const, and store the result on register reg1. Memory regions stores (store result into a variable, for
//instance) are NOT ALLOWED.
void AND(operationInfo lineInfo, int registers[], int variables[]) {
    //lineInfo.value1 is the register to be loaded
    printf("Register number %d with the value %d\n", lineInfo.value1, registers[lineInfo.value1]);

    //translate decimal to binary of the value of the register
    int temp_value1 = registers[lineInfo.value1];
    int binary1[8] = {0};

    for (int i = 7; i >= 0; i--) {
        binary1[i] = temp_value1 % 2;
        temp_value1 = temp_value1 / 2;
    }
    //print binary1
    printf("binary1 :");
    for (int k = 0; k < 8; k++) {
        printf("%d", binary1[k]);
    }
    printf("\n");


    int temp_value2;
    int binary2[8] = {0};
    int j = 0;

    // if type2 is a register
    if (lineInfo.type2 == 1){
        //Translate decimal to binary of the value of the register
        printf("Register number %d with the value %d\n", lineInfo.value2, registers[lineInfo.value2]);
        temp_value2 = registers[lineInfo.value2];
    }

    //if type2 is a variable
    else if(lineInfo.type2 == 2){
        //Translate decimal to binary of the value of the variable
        printf("Variable number %d with the value %d\n", lineInfo.value2, variables[lineInfo.value2]);
        temp_value2 = variables[lineInfo.value2];
    }

    //if type2 is a constant
    else if(lineInfo.type2 == 3){
        //Translate decimal to binary of the value of the constant
        printf("Constant with the value %d\n", lineInfo.value2);
        temp_value2 = lineInfo.value2;
    }

    for (int i = 7; i >= 0; i--) {
        binary2[i] = temp_value2 % 2;
        temp_value2 = temp_value2 / 2;
    }

    //print binary2
    printf("binary2 :");
    for (int k = 0; k < 8; k++) {
        printf("%d", binary2[k]);
    }printf("\n");

    //AND operation
    int result[8];
    for (int k = 0; k < 8; k++) {
        if (binary1[k] == 1 && binary2[k] == 1) {
            result[k] = 1;
        } else {
            result[k] = 0;
        }
    }
    printf("result :");
    for (int k = 0; k < 8; k++) {
        printf("%d", result[k]);
    }printf("\n");


    //translate binary to decimal
    int decimal = 0;
    for (int k = 0; k < 8; k++){
        decimal += result[k] * pow(2, 7-k);
    }
    printf("%d\n", decimal);

    //Put the result in the register
    registers[lineInfo.value1] = decimal;

}

//NOT <reg> - OP Code 00000
//Performs a logical NOT operation on register reg and store the result on register reg. Memory
//regions stores (store result into a variable, for instance) are NOT ALLOWED.
void NOT(operationInfo lineInfo, int registers[]) {
    //lineInfo.value1 is the register to be loaded
    printf("Register number %d\n", lineInfo.value1);

    //translate decimal to binary of the value of the register
    int temp_value1 = registers[lineInfo.value1];
    int binary1[8] = {0};

    for (int i = 7; i >= 0; i--) {
        binary1[i] = temp_value1 % 2;
        temp_value1 = temp_value1 / 2;
    }
    //print binary1
    printf("binary1 :");
    for (int k = 0; k < 8; k++) {
        printf("%d", binary1[k]);
    }
    printf("\n");

    //NOT operation
    int result[8];
    for (int k = 0; k < 8; k++){
        if (binary1[k] == 1) {
            result[k] = 0;
        } else {
            result[k] = 1;
        }
    }

    printf("result :");
    for (int k = 0; k < 8; k++) {
        printf("%d", result[k]);
    }printf("\n");


    //translate binary to decimal
    int decimal = 0;
    for (int k = 0; k < 8; k++){
        decimal += result[k] * pow(2, 7-k);
    }
    printf("%d\n", decimal);

    //Put the result in the register
    registers[lineInfo.value1] = decimal;


}

//SUB <reg1> <reg2>/<var>/<const> - OP Code 00110
//Performs the subtraction operation of reg1 and a register reg2, a variable var or a constant const,
//and store the result on register reg1. The operation is given by second argument minus the first
//argument (i.e., reg2 – reg1). Memory regions stores (store result into a variable, for instance) are
//NOT ALLOWED.
void SUB(operationInfo lineInfo, int registers[], int variables[]){
    //lineInfo.value1 is the register to be loaded
    printf("Register number %d\n", lineInfo.value1);

}