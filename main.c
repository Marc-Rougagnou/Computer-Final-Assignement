//
// Created by Marc on 02/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function_main.h"
#include "operation_pair.h"
#include "odd_operations.h"
#include "display.h"

int main() {

    int registers[4] = {0,0,0,0};//Registers t0 on 0 t1 on 1 t2 on 2 and t3 on 3

    int variables[26];//create the variables for all the letters of the alphabet
    for (int i = 0; i < 26; ++i) {
        variables[i] = 0;
    }

    int variables_use[26];//create the variables for all the letters of the alphabet
    for (int i = 0; i < 26; ++i) {
        variables_use[i] = -1;
    }

    int stack[32];//create the stack

    int pc = 1;//program counter
    int line_program = 0;//line of the program
    int sp = 0;//stack pointer
    char **tabPC = malloc(32 * sizeof(char *));

    //Readind of the test.txt file
    FILE *fichier = fopen("..\\test.txt", "r");
    if (fichier != NULL) {
        printf("File opened\n");

        // Read by pack of 32 characters
        char chaine1[33];

        // Create a table 2 dimensions of char
        int j = 0;
        while (fread(chaine1, 32, 1, fichier) != 0) {
            tabPC[j] = malloc(33 * sizeof(char));
            chaine1[32] = '\0';
            strncpy(tabPC[j], chaine1, 32);
            j++;
            line_program++;
        }
        fclose(fichier);
    }
    else {
        printf("Error opening the file\n");
        return 0;
    }

    if(line_program == 0){
        printf("Error: the file is empty\n");
        return 0;
    }

    for (int i = 0; i < line_program; ++i) {
        display_line(giveInfoLine(tabPC[i], variables_use));
    }
    printf("\nStart the execution: \n\n");
    wait();
    //browse table tabPC (pc is line +1)

    while (pc != line_program + 1){
        operationInfo lineInfo = giveInfoLine(tabPC[pc - 1], variables_use);


        display_line(lineInfo);

        switch (lineInfo.operation) {
            case 0: {
                LDA(lineInfo, registers, variables);
                break;
            }
            case 1: { ;
                STR(lineInfo, registers, variables);
                break;
            }
            case 2: {
                PUSH(lineInfo, registers, variables, stack, &sp);
                break;
            }
            case 3: {
                if (sp != 0) {
                    POP(lineInfo, stack, &sp, registers);
                }
                break;
            }
            case 4: {
                AND(lineInfo, registers, variables);
                break;
            }
            case 5: {
                OR(lineInfo, registers, variables);
                break;
            }
            case 6: {
                NOT(lineInfo, registers);
                break;
            }
            case 7: {
                ADD(lineInfo, registers, variables);
                break;
            }
            case 8: {
                SUB(lineInfo, registers, variables);
                break;
            }
            case 9: {
                DIV(lineInfo, registers, variables);
                break;
            }
            case 10: {
                MUL(lineInfo, registers, variables);
                break;
            }
            case 11: {
                MOD(lineInfo, registers, variables);
                break;
            }
            case 12: {
                INC(lineInfo, registers);
                break;
            }
            case 13: {
                DEC(lineInfo, registers);
                break;
            }
            case 14: {
                BEQ(lineInfo, registers, variables, &pc);
                break;
            }
            case 15: {
                BNE(lineInfo, registers, variables, &pc);
                break;
            }
            case 16: {
                BBG(lineInfo, registers, variables, &pc);
                break;
            }
            case 17: {
                BSM(lineInfo, registers, variables, &pc);
                break;
            }
            case 18: {
                JMP(lineInfo, &pc);
                break;
            }
            case 19: {
                pc = line_program;
                break;
            }
        }
        //display all the registers
        display_register(registers);
        //display all the variables
        display_variables(variables, variables_use);
        //display all the stack
        display_stack(stack, sp);
        //display the program counter
        pc++;
        display_pc(pc);
        if (pc != line_program + 1) {
            lineInfo = giveInfoLine(tabPC[pc - 1], variables_use);
            printf("The next instruction is: ");
            display_line(lineInfo);
            //wait for the user to input "ok"
            wait();
        }

    }
    printf("The program is finished\n");

}