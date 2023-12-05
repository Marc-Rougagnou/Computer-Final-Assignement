//
// Created by Marc on 03/12/2023.
//

#include "operation_pair.h"
#include "function_main.h"
#include "stdio.h"


void STR(operationInfo lineInfo, int registers[], int variables[]){
    //store const/reg dans la var
    if (lineInfo.type2==1){
        variables[lineInfo.value1]=registers[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        variables[lineInfo.value1]=lineInfo.value2;
    }
}

void POP(operationInfo lineInfo, int stack[],int sp, int registers[]){
    registers[lineInfo.value1]=stack[sp];
}// faire sp-- après avoir fait pop pour mettre à jour la stack
//vérifier que la stack n'est pas vide

void OR(operationInfo lineInfo, int registers[], int variables[]){

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

void ADD(operationInfo lineInfo, int registers[],int variables[]){
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
    registers[lineInfo.value1]--;
}