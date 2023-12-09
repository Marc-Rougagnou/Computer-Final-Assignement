//
// Created by Marc on 09/12/2023.
//

#ifndef COMPUTER_COMPARE_H
#define COMPUTER_COMPARE_H
#include "function_main.h"
#include <stdio.h>
#include <stdlib.h>
void BNE(operationInfo lineInfo, int registers[], int variables[], int *pc);
void BSM(operationInfo lineInfo, int registers[], int variables[], int *pc);
void BEQ(operationInfo lineInfo, int registers[], int variables[], int *pc);
void BBG(operationInfo lineInfo, int registers[], int variables[], int *pc);
void JMP(operationInfo lineInfo, int *pc);
#endif //COMPUTER_COMPARE_H
