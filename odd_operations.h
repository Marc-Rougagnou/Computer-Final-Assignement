//
// Created by yael1 on 04/12/2023.
//

#ifndef COMPUTER_FINAL_ASSIGNEMENT_ODD_OPERATIONS_H
#define COMPUTER_FINAL_ASSIGNEMENT_ODD_OPERATIONS_H

#include "function_main.h"

void LDA(operationInfo lineInfo, int registers[], int variables[]);
void PUSH(operationInfo lineInfo, int registers[], int variables[], int stack[], int *sp);
void AND(operationInfo lineInfo, int registers[], int variables[]);
void NOT(operationInfo lineInfo, int registers[]);
void SUB(operationInfo lineInfo, int registers[], int variables[]);
void MUL(operationInfo lineInfo, int registers[], int variables[]);
void INC(operationInfo lineInfo, int registers[]);
void BEQ(operationInfo lineInfo, int registers[], int variables[], int *pc);
#endif //COMPUTER_FINAL_ASSIGNEMENT_ODD_OPERATIONS_H
