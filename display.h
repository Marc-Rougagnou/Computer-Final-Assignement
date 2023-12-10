//
// Created by Marc on 06/12/2023.
//

#ifndef COMPUTER_DISPLAY_H
#define COMPUTER_DISPLAY_H
#include "stdio.h"
#include "function_main.h"

void display_register(int registers[]);
void display_pc(int pc);
void display_stack(int stack[], int sp);
void display_variables(int variables[], int variables_use[]);
void display_line(operationInfo lineInfo);
#endif //COMPUTER_DISPLAY_H
