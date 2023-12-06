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

void BNE(operationInfo lineInfo, int registers[], int variables[], int *pc){
    if (lineInfo.type1==1){
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
    else if (lineInfo.type1==2){
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
    else if (lineInfo.type1==3){
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
    if (lineInfo.type1==1){
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
    else if (lineInfo.type1==2){
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
    else if (lineInfo.type1==3){
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

