//
// Created by Marc on 09/12/2023.
//

#ifndef COMPUTER_MEMORY_FUNCTION_H
#define COMPUTER_MEMORY_FUNCTION_H
#include "function_main.h"
#include <stdio.h>
#include <stdlib.h>

void STR(operationInfo lineInfo, int registers[], int variables[], int variables_use[]);
void POP(operationInfo lineInfo, int stack[],int sp, int registers[]);
void LDA(operationInfo lineInfo, int registers[], int variables[]);
void PUSH(operationInfo lineInfo, int registers[], int variables[], int stack[], int sp);
#endif //COMPUTER_MEMORY_FUNCTION_H
