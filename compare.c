//
// Created by Marc on 09/12/2023.
//

#include "compare.h"
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
            }
            //Type 2 variable
        }else if (lineInfo.type2 == 2){
            if (registers[lineInfo.value1] == variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }
            //Type 2 constant
        }else if(lineInfo.type2 == 3){
            if (registers[lineInfo.value1] == lineInfo.value2){
                *pc = lineInfo.label;
            }
        }

        //Type 1 variable
    }else if(lineInfo.type1 == 2){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(variables[lineInfo.value1] == registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }
            //Type 2 variable
        } else if (lineInfo.type2 == 2){
            if (variables[lineInfo.value1] == variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }
        }
            //Type 2 constant
        else if(lineInfo.type2 == 3){
            if (variables[lineInfo.value1] == lineInfo.value2){
                *pc = lineInfo.label;
            }
        }
    }

        // Type 1 constant
    else if (lineInfo.type1 == 3){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(lineInfo.value1 == registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }
            //Type 2 variable
        }else if(lineInfo.type2 == 2){
            if(lineInfo.value1 == variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }
        }else if(lineInfo.type2 == 3){
            if(lineInfo.value1 == lineInfo.value2){
                *pc = lineInfo.label;
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
            }

            //Type 2 variable
        }else if (lineInfo.type2 == 2){
            if (registers[lineInfo.value1] > variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }
            //Type 2 constant
        }else if(lineInfo.type2 == 3){
            if (registers[lineInfo.value1] > lineInfo.value2){
                *pc = lineInfo.label;
            }
        }

        //Type 1 variable
    }else if(lineInfo.type1 == 2){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(variables[lineInfo.value1] > registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }
            //Type 2 variable
        } else if (lineInfo.type2 == 2){
            if (variables[lineInfo.value1] > variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }
        }
            //Type 2 constant
        else if(lineInfo.type2 == 3){
            if (variables[lineInfo.value1] > lineInfo.value2){
                *pc = lineInfo.label;
            }
        }

    }
        // Type 1 constant
    else if (lineInfo.type1 == 3){
        //Type 2 register
        if(lineInfo.type2 == 1){
            if(lineInfo.value1 > registers[lineInfo.value2]){
                *pc = lineInfo.label;
            }
            //Type 2 variable
        }else if(lineInfo.type2 == 2){
            if(lineInfo.value1 > variables[lineInfo.value2]){
                *pc = lineInfo.label;
            }
        }else if(lineInfo.type2 == 3){
            if(lineInfo.value1 > lineInfo.value2){
                *pc = lineInfo.label;
            }
        }
    }
}

//JMP <LABEL> - OP Code 10000
//Jump to the address defined by the label LABEL
void JMP(operationInfo lineInfo, int *pc){
    *pc = lineInfo.label;
}