//
// Created by Marc on 09/12/2023.
//

#include "arthimetic_function.h"

void ADD(operationInfo lineInfo, int registers[],int variables[]){
    //execute the ADD operation between the two given parameters and store the result in the first parameter
    if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value1] + registers[lineInfo.value2];
    }
    else if (lineInfo.type2==2){
        registers[lineInfo.value1]=registers[lineInfo.value1] + variables[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=registers[lineInfo.value1] + lineInfo.value2;
    }
}

void DIV(operationInfo lineInfo, int registers[], int variables[]){
    //execute the DIV operation between the two given parameters and store the result in the first parameter
    if (lineInfo.type2==1){
        registers[lineInfo.value1]= registers[lineInfo.value2] / registers[lineInfo.value1];
    }
    else if (lineInfo.type2==2){
        registers[lineInfo.value1]=variables[lineInfo.value2] / registers[lineInfo.value1] ;
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]= lineInfo.value2 / registers[lineInfo.value1];
    }
}

void MOD(operationInfo lineInfo, int registers[], int variables[]){
    //execute the MOD (modulo) operation between the two given parameters and store the result in the first parameter
    if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value2] % registers[lineInfo.value1];
    }
    else if (lineInfo.type2==2){
        registers[lineInfo.value1]=variables[lineInfo.value2] % registers[lineInfo.value1];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=lineInfo.value2 % registers[lineInfo.value1];
    }

}

void DEC(operationInfo lineInfo, int registers[]){
    //decrement the given register by 1
    registers[lineInfo.value1]--;
}


//SUB <reg1> <reg2>/<var>/<const> - OP Code 00110
//Performs the subtraction operation of reg1 and a register reg2, a variable var or a constant const,
//and store the result on register reg1. The operation is given by second argument minus the first
//argument (i.e., reg2 – reg1). Memory regions stores (store result into a variable, for instance) are
//NOT ALLOWED.
void SUB(operationInfo lineInfo, int registers[], int variables[]){
    //lineInfo.value1 is the register to be loaded

    if (lineInfo.type2 == 1){
        registers[lineInfo.value1] = registers[lineInfo.value2] - registers[lineInfo.value1];
    }
    else if (lineInfo.type2 == 2){
        registers[lineInfo.value1] = variables[lineInfo.value2] - registers[lineInfo.value1];
    }
    else if (lineInfo.type2 == 3){
        registers[lineInfo.value1] = lineInfo.value2 - registers[lineInfo.value1];
    }

}

//MUL <reg1> <reg2>/<var>/<const> - OP Code 01000
//Performs the integer multiplication operation of reg1 and a register reg2, a variable var or a
//constant const, and store the result on register reg1. Memory regions stores (store result into a
//variable, for instance) are NOT ALLOWED
void MUL(operationInfo lineInfo, int registers[], int variables[]){
    if (lineInfo.type2 == 1){
        registers[lineInfo.value1] =  registers[lineInfo.value1] * registers[lineInfo.value2];
    }
    else if (lineInfo.type2 == 2){
        registers[lineInfo.value1] = registers[lineInfo.value1] * variables[lineInfo.value2];
    }
    else if (lineInfo.type2 == 3){
        registers[lineInfo.value1] = registers[lineInfo.value1] * lineInfo.value2;
    }
}

//INC <reg> - OP Code 01010
//Increments the value of a register reg. Memory increments (incrementing a variable, for instance)
//are NOT ALLOWED.
void INC(operationInfo lineInfo, int registers[]){
    //registers[lineInfo.value1] = registers[lineInfo.value1] + 1;
    registers[lineInfo.value1]++;
}