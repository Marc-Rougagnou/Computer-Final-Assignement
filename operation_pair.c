//
// Created by Marc on 03/12/2023.
//

#include "operation_pair.h"
#include "function_main.h"
#include "stdio.h"


void STR(operationInfo lineInfo, char registers[], char variables[]){

    //demander pas compris ce qu'il fallait faire
}

void POP(operationInfo lineInfo, char stack[],int sp, char registers[]){
    registers[lineInfo.value1]=stack[sp];
}// faire sp-- après avoir fait pop

void OR(operationInfo lineInfo, char registers[], char variables[]){
    if (lineInfo.type2==2){
        registers[lineInfo.value1]=registers[lineInfo.value1] | variables[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=registers[lineInfo.value1] | lineInfo.value2;
    }
    else if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value1] | registers[lineInfo.value2];
    }
}

void ADD(operationInfo lineInfo, char registers[],char variables[]){
    if (lineInfo.type2==2){
        registers[lineInfo.value1]=registers[lineInfo.value1] + variables[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=registers[lineInfo.value1] + lineInfo.value2;
    }
    else if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value1] + registers[lineInfo.value2];
    }
}

void DIV(operationInfo lineInfo, char registers[], char variables[]){
    if (lineInfo.type2==2){
        registers[lineInfo.value1]=registers[lineInfo.value1] / variables[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=registers[lineInfo.value1] / lineInfo.value2;
    }
    else if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value1] / registers[lineInfo.value2];
    }
}

void MOD(operationInfo lineInfo, char registers[], char variables[]){
    if (lineInfo.type2==2){
        registers[lineInfo.value1]=registers[lineInfo.value1] % variables[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        registers[lineInfo.value1]=registers[lineInfo.value1] % lineInfo.value2;
    }
    else if (lineInfo.type2==1){
        registers[lineInfo.value1]=registers[lineInfo.value1] % registers[lineInfo.value2];
    }
}

void DEC(operationInfo lineInfo, char registers[]){
    registers[lineInfo.value1]--;
}