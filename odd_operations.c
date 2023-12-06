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

    if (lineInfo.type2 == 1){
        printf("t%d - t%d store in t%d\n", lineInfo.value2, lineInfo.value1, lineInfo.value1);
        registers[lineInfo.value1] = registers[lineInfo.value2] - registers[lineInfo.value1];
    }
    else if (lineInfo.type2 == 2){
        printf("t%d - Var%d store in t%d\n", lineInfo.value2, lineInfo.value1, lineInfo.value1);
        registers[lineInfo.value1] = variables[lineInfo.value2] - registers[lineInfo.value1];
    }
    else if (lineInfo.type2 == 3){
        printf("t%d - %d store in t%d\n", lineInfo.value2, lineInfo.value1, lineInfo.value1);
        registers[lineInfo.value1] = lineInfo.value2 - registers[lineInfo.value1];
    }

}

//MUL <reg1> <reg2>/<var>/<const> - OP Code 01000
//Performs the integer multiplication operation of reg1 and a register reg2, a variable var or a
//constant const, and store the result on register reg1. Memory regions stores (store result into a
//variable, for instance) are NOT ALLOWED
void MUL(operationInfo lineInfo, int registers[], int variables[]){
    if (lineInfo.type2 == 1){
        printf("t%d x t%d store in t%d\n", lineInfo.value1, lineInfo.value2, lineInfo.value1);
        registers[lineInfo.value1] =  registers[lineInfo.value1] * registers[lineInfo.value2];
    }
    else if (lineInfo.type2 == 2){
        printf("t%d * Var%d\n", lineInfo.value1, lineInfo.value2);
        registers[lineInfo.value1] = registers[lineInfo.value1] * variables[lineInfo.value2];
    }
    else if (lineInfo.type2 == 3){
        printf("t%d * %d\n", lineInfo.value1, lineInfo.value2);
        registers[lineInfo.value1] = registers[lineInfo.value1] * lineInfo.value2;
    }
}

//INC <reg> - OP Code 01010
//Increments the value of a register reg. Memory increments (incrementing a variable, for instance)
//are NOT ALLOWED.
void INC(operationInfo lineInfo, int registers[]){
    printf("t%d++\n", lineInfo.value1);
    //registers[lineInfo.value1] = registers[lineInfo.value1] + 1;
    registers[lineInfo.value1]++;
}

//BEQ <reg1>/<var1>/<const1> <reg2>/<var2>/<const2> <LABEL> - OP Code 01100
//Performs a comparison between two values, given by registers, variables or constants. Any
//combination is permitted. If they are equal, jump to the address defined by the label LABEL
void BEQ(operationInfo lineInfo, int registers[], int variables[], int *pc){

    //Type 1 register
    if (lineInfo.type1 == 1){
        //Type 2 register
        if (lineInfo.type2 == 1){
            if (registers[lineInfo.value1] == registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("t%d and t%d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        //Type 2 variable
        }else if (lineInfo.type2 == 2){
            if (registers[lineInfo.value1] == variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("t%d and Var%d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        //Type 2 constant
        }else if(lineInfo.type2 == 3){
            if (registers[lineInfo.value1] == lineInfo.value2){
                *pc = lineInfo.label;
            }else{
                printf("t%d and %d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        }

    //Type 1 variable
    }else if(lineInfo.type1 == 2){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(variables[lineInfo.value1] == registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("Var%d and t%d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        //Type 2 variable
        } else if (lineInfo.type2 == 2){
            if (variables[lineInfo.value1] == variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("Var%d and Var%d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        }
        //Type 2 constant
        else if(lineInfo.type2 == 3){
            if (variables[lineInfo.value1] == lineInfo.value2){
                *pc = lineInfo.label;
            }else{
                printf("Var%d and %d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        }

    }
    // Type 1 constant
    else if (lineInfo.type1 == 3){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(lineInfo.value1 == registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("%d and t%d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        //Type 2 variable
        }else if(lineInfo.type2 == 2){
            if(lineInfo.value1 == variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("%d and Var%d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        }else if(lineInfo.type2 == 3){
            if(lineInfo.value1 == lineInfo.value2){
                *pc = lineInfo.label;
            }else{
                printf("%d and %d are not equal\n", lineInfo.value1, lineInfo.value2);
            }
        }
    }
}

//BBG <reg1>/<var1>/<const1> <reg2>/<var2>/<const2> <LABEL> - OP Code 01110
//Performs a comparison between two values, given by registers, variables or constants. Any
//combination is permitted. If the first parameter is bigger than the second parameter, jump to the
//address defined by the label LABEL
void BBG(operationInfo lineInfo, int registers[], int variables[], int *pc){
    //Type 1 register
    if (lineInfo.type1 == 1){
        //Type 2 register
        if (lineInfo.type2 == 1){
            if (registers[lineInfo.value1] > registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("t%d < t%dl\n", lineInfo.value1, lineInfo.value2);
            }
            //Type 2 variable
        }else if (lineInfo.type2 == 2){
            if (registers[lineInfo.value1] > variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("t%d < Var%d\n", lineInfo.value1, lineInfo.value2);
            }
            //Type 2 constant
        }else if(lineInfo.type2 == 3){
            if (registers[lineInfo.value1] > lineInfo.value2){
                *pc = lineInfo.label;
            }else{
                printf("t%d < %d\n", lineInfo.value1, lineInfo.value2);
            }
        }

        //Type 1 variable
    }else if(lineInfo.type1 == 2){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(variables[lineInfo.value1] > registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("Var%d < t%d\n", lineInfo.value1, lineInfo.value2);
            }
            //Type 2 variable
        } else if (lineInfo.type2 == 2){
            if (variables[lineInfo.value1] > variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("Var%d < Var%d\n", lineInfo.value1, lineInfo.value2);
            }
        }
            //Type 2 constant
        else if(lineInfo.type2 == 3){
            if (variables[lineInfo.value1] > lineInfo.value2){
                *pc = lineInfo.label;
            }else{
                printf("Var%d < %d\n", lineInfo.value1, lineInfo.value2);
            }
        }

    }
        // Type 1 constant
    else if (lineInfo.type1 == 3){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(lineInfo.value1 > registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("%d < t%d\n", lineInfo.value1, lineInfo.value2);
            }
            //Type 2 variable
        }else if(lineInfo.type2 == 2){
            if(lineInfo.value1 > variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }else{
                printf("%d < Var%d\n", lineInfo.value1, lineInfo.value2);
            }
        }else if(lineInfo.type2 == 3){
            if(lineInfo.value1 > lineInfo.value2){
                *pc = lineInfo.label;
            }else{
                printf("%d < %d\n", lineInfo.value1, lineInfo.value2);
            }
        }
    }
}

//JMP <LABEL> - OP Code 10000
//Jump to the address defined by the label LABEL
void JMP(operationInfo lineInfo, int *pc){
    *pc = lineInfo.label;
}