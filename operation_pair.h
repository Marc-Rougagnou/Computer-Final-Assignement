//
// Created by Marc on 03/12/2023.
//

#ifndef COMPUTER_FINAL_ASSIGNEMENT_OPERATION_PAIR_H
#define COMPUTER_FINAL_ASSIGNEMENT_OPERATION_PAIR_H

#include "function_main.h"
void STR(operationInfo lineInfo, int registers[], int variables[]);//done
void POP(operationInfo lineInfo, int stack[],int *sp, int registers[]);//done
void OR(operationInfo lineInfo, int registers[], int variables[]);//done
void ADD(operationInfo lineInfo, int registers[],int variables[]);//done
void DIV(operationInfo lineInfo, int registers[], int variables[]);//done
void MOD(operationInfo lineInfo, int registers[], int variables[]);//done
void DEC(operationInfo lineInfo, int registers[]);//done
void BNE(operationInfo lineInfo, int registers[], int variables[], int *pc);//done
void BSM(operationInfo lineInfo, int registers[], int variables[], int *pc);

#endif //COMPUTER_FINAL_ASSIGNEMENT_OPERATION_PAIR_H
