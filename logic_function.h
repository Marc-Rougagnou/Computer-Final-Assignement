//
// Created by Marc on 09/12/2023.
//

#ifndef COMPUTER_LOGIC_FUNCTION_H
#define COMPUTER_LOGIC_FUNCTION_H
#include "function_main.h"
#include <stdio.h>
#include <stdlib.h>

void OR(operationInfo lineInfo, int registers[], int variables[]);
void AND(operationInfo lineInfo, int registers[], int variables[]);
void NOT(operationInfo lineInfo, int registers[]);

#endif //COMPUTER_LOGIC_FUNCTION_H
