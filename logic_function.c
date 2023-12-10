//
// Created by Marc on 09/12/2023.
//

#include "logic_function.h"
#include "math.h"


void OR(operationInfo lineInfo, int registers[], int variables[]){
    //execute the OR operation between the two given parameters and store the result in the first parameter
    if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value1] | registers[lineInfo.value2];
    }
    else if (lineInfo.type2==2){
        registers[lineInfo.value1]=registers[lineInfo.value1] | variables[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=registers[lineInfo.value1] | lineInfo.value2;
    }
}

//AND <reg1> <reg2>/<var>/<const> - OP Code 00011
//Performs a logical AND operation between reg1 and a register reg2, a variable var or a constant
//const, and store the result on register reg1. Memory regions stores (store result into a variable, for
//instance) are NOT ALLOWED.
void AND(operationInfo lineInfo, int registers[], int variables[]) {
    //lineInfo.value1 is the register to be loaded
    //translate decimal to binary of the value of the register
    int temp_value1 = registers[lineInfo.value1];
    int binary1[8] = {0};

    for (int i = 7; i >= 0; i--) {
        binary1[i] = temp_value1 % 2;
        temp_value1 = temp_value1 / 2;
    }

    int temp_value2;
    int binary2[8] = {0};
    int j = 0;

    // if type2 is a register
    if (lineInfo.type2 == 1){
        //Translate decimal to binary of the value of the register
        temp_value2 = registers[lineInfo.value2];
    }

        //if type2 is a variable
    else if(lineInfo.type2 == 2){
        //Translate decimal to binary of the value of the variable
        temp_value2 = variables[lineInfo.value2];
    }

        //if type2 is a constant
    else if(lineInfo.type2 == 3){
        //Translate decimal to binary of the value of the constant
        temp_value2 = lineInfo.value2;
    }

    for (int i = 7; i >= 0; i--) {
        binary2[i] = temp_value2 % 2;
        temp_value2 = temp_value2 / 2;
    }

    //AND operation
    int result[8];
    for (int k = 0; k < 8; k++) {
        if (binary1[k] == 1 && binary2[k] == 1) {
            result[k] = 1;
        } else {
            result[k] = 0;
        }
    }

    //translate binary to decimal
    int decimal = 0;
    for (int k = 0; k < 8; k++){
        decimal += result[k] * pow(2, 7-k);
    }

    //Put the result in the register
    registers[lineInfo.value1] = decimal;
}

//NOT <reg> - OP Code 00000
//Performs a logical NOT operation on register reg and store the result on register reg. Memory
//regions stores (store result into a variable, for instance) are NOT ALLOWED.
void NOT(operationInfo lineInfo, int registers[]) {
    //translate decimal to binary of the value of the register
    int temp_value1 = registers[lineInfo.value1];
    int binary1[8] = {0};

    for (int i = 7; i >= 0; i--) {
        binary1[i] = temp_value1 % 2;
        temp_value1 = temp_value1 / 2;
    }

    //NOT operation
    int result[8];
    for (int k = 0; k < 8; k++){
        if (binary1[k] == 1) {
            result[k] = 0;
        } else {
            result[k] = 1;
        }
    }

    //translate binary to decimal
    int decimal = 0;
    for (int k = 0; k < 8; k++){
        decimal += result[k] * pow(2, 7-k);
    }

    //Put the result in the register
    registers[lineInfo.value1] = decimal;


}