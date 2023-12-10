//
// Created by Marc on 09/12/2023.
//

#include "memory_function.h"

void STR(operationInfo lineInfo, int registers[], int variables[], int variables_use[]){
    //store const/reg in the given var
    variables_use[lineInfo.value1]=1;
    if (lineInfo.type2==1){
        variables[lineInfo.value1]=registers[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        variables[lineInfo.value1]=lineInfo.value2;
    }
}

void POP(operationInfo lineInfo, int stack[],int sp, int registers[]){
    registers[lineInfo.value1]=stack[sp-1];
}

//LDA operation : LDA <reg1> <reg2>/<var>/<const> - OP Code 00000
//Load register reg1 with the contents of either the contents of reg2, or the memory var or a constant
//const. Memory regions loads (load into a variable, for instance) are NOT ALLOWED
void LDA(operationInfo lineInfo, int registers[], int variables[]){
    // if type2 is a register
    if (lineInfo.type2==1){
        registers[lineInfo.value1] = registers[lineInfo.value2];
    }

        // if type2 is a variable
    else if (lineInfo.type2==2){
        registers[lineInfo.value1] = variables[lineInfo.value2];
    }

        // if type2 is a constant
    else if (lineInfo.type2==3){
        registers[lineInfo.value1] = lineInfo.value2;
    }
}

//PUSH <reg>/<var>/<const> - OP Code 00010
//Push to the top of the stack the contents of reg or var or a constant const
void PUSH(operationInfo lineInfo, int registers[], int variables[], int stack[], int sp){
    // if type1 is a register
    if (lineInfo.type1==1){
        stack[sp] = registers[lineInfo.value1];
    }

        // if type1 is a variable
    else if (lineInfo.type1==2){
        stack[sp] = variables[lineInfo.value1];
    }

        // if type1 is a constant
    else if (lineInfo.type1==3){
        stack[sp] = (lineInfo.value1);
    }
}