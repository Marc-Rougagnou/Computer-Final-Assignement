//
// Created by Marc on 06/12/2023.
//

#ifndef COMPUTER_DISPLAY_H
#define COMPUTER_DISPLAY_H
#include "stdio.h"
#include "function_main.h"

void display_register(int registers[]);
void display_pc(int pc);
void display_tabPC(char **tabPC);
void display_stack(int stack[]);
void display_sp(int sp);
void display_line(operationInfo lineInfo);
#endif //COMPUTER_DISPLAY_H
