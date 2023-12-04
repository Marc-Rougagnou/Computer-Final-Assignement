//
// Created by Marc on 03/12/2023.
//

#ifndef COMPUTER_FINAL_ASSIGNEMENT_OPERATION_PAIR_H
#define COMPUTER_FINAL_ASSIGNEMENT_OPERATION_PAIR_H

#include "function_main.h"
void STR(operationInfo lineInfo, char registers[], char variables[]);
void POP(operationInfo lineInfo, char stack[],int sp, char registers[]);
void OR(operationInfo lineInfo, char registers[], char variables[]);
void ADD(operationInfo lineInfo, char registers[],char variables[]);
void DIV(operationInfo lineInfo, char registers[], char variables[]);
void MOD(operationInfo lineInfo, char registers[], char variables[]);
void DEC(operationInfo lineInfo, char registers[], char variables[]);

#endif //COMPUTER_FINAL_ASSIGNEMENT_OPERATION_PAIR_H
