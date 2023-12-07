//
// Created by Marc on 03/12/2023.
//

#include "operation_pair.h"
#include "function_main.h"
#include "stdio.h"


void STR(operationInfo lineInfo, int registers[], int variables[]){
    //store const/reg in the given var
    if (lineInfo.type2==1){
        variables[lineInfo.value1]=registers[lineInfo.value2];
    }
    else if (lineInfo.type2==3){
        variables[lineInfo.value1]=lineInfo.value2;
    }
}

void POP(operationInfo lineInfo, int stack[],int *sp, int registers[]){
    registers[lineInfo.value1]=stack[*sp];
    *sp--;
}// faire sp-- après avoir fait pop pour mettre à jour la stack
//vérifier que la stack n'est pas vide

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

void BNE(operationInfo lineInfo, int registers[], int variables[], int *pc){
    //if the two given parameters are not equal, jump to the given label
    if (lineInfo.type1==1){// if the first parameter is a register
        if (lineInfo.type2==1){
            if (registers[lineInfo.value1]!=registers[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==2){
            if (registers[lineInfo.value1]!=variables[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==3){
            if (registers[lineInfo.value1]!=lineInfo.value2){
                *pc=lineInfo.label;
            }
        }
    }
    else if (lineInfo.type1==2){// if the first parameter is a variable
        if (lineInfo.type2==1){
            if (variables[lineInfo.value1]!=registers[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==2){
            if (variables[lineInfo.value1]!=variables[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==3){
            if (variables[lineInfo.value1]!=lineInfo.value2){
                *pc=lineInfo.label;
            }
        }
    }
    else if (lineInfo.type1==3){// if the first parameter is a constant
        if (lineInfo.type2==1){
            if (lineInfo.value1!=registers[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==2){
            if (lineInfo.value1!=variables[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==3){
            if (lineInfo.value1!=lineInfo.value2){
                *pc=lineInfo.label;
            }
        }
    }
}

void BSM(operationInfo lineInfo, int registers[], int variables[], int *pc){
    //if the first value is smaller than the second one, jump to the given label
    if (lineInfo.type1==1){// if the first parameter is a register
        if (lineInfo.type2==1){
            if (registers[lineInfo.value1]<registers[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==2){
            if (registers[lineInfo.value1]<variables[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==3){
            if (registers[lineInfo.value1]<lineInfo.value2){
                *pc=lineInfo.label;
            }
        }
    }
    else if (lineInfo.type1==2){// if the first parameter is a variable
        if (lineInfo.type2==1){
            if (variables[lineInfo.value1]<registers[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==2){
            if (variables[lineInfo.value1]<variables[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==3){
            if (variables[lineInfo.value1]<lineInfo.value2){
                *pc=lineInfo.label;
            }
        }
    }
    else if (lineInfo.type1==3){// if the first parameter is a constant
        if (lineInfo.type2==1){
            if (lineInfo.value1<registers[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==2){
            if (lineInfo.value1<variables[lineInfo.value2]){
                *pc=lineInfo.label;
            }
        }
        if (lineInfo.type2==3){
            if (lineInfo.value1<lineInfo.value2){
                *pc=lineInfo.label;
            }
        }
    }
}

