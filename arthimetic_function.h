//
// Created by Marc on 09/12/2023.
//

#ifndef COMPUTER_ARTHIMETIC_FUNCTION_H
#define COMPUTER_ARTHIMETIC_FUNCTION_H
#include "function_main.h"
#include <stdio.h>
#include <stdlib.h>

void ADD(operationInfo lineInfo, int registers[],int variables[]);
void DIV(operationInfo lineInfo, int registers[], int variables[]);
void MOD(operationInfo lineInfo, int registers[], int variables[]);
void DEC(operationInfo lineInfo, int registers[]);
void SUB(operationInfo lineInfo, int registers[], int variables[]);
void MUL(operationInfo lineInfo, int registers[], int variables[]);
void INC(operationInfo lineInfo, int registers[]);

#endif //COMPUTER_ARTHIMETIC_FUNCTION_H
