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

    int registers[4] = {8, 7, 0, 14};//Registers t0 on 0 t1 on 1 t2 on 2 and t3 on 3

    int variables[8];//create the variables

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
    variables[0] = 2;
    variables[1] = 5;

    

    //browse table tabPC (pc is line +)
    printf("The value of the program counter is %d\n", pc);
    while (pc != line_program + 1){
        printf("I am in the while\n");
        operationInfo lineInfo = giveInfoLine(tabPC[pc - 1]);
        display_line(lineInfo);

        switch (lineInfo.operation) {
            case 0:{
                printf("0 : LDA\n");
                LDA(lineInfo, registers, variables);
                printf("register t%d have the value: %d\n", lineInfo.value1, registers[lineInfo.value1]);
                wait();
                pc++;
                break;
            }
            case 1:{
                printf("1 : STR\n");
                STR(lineInfo, registers, variables);
                wait();
                pc++;
                break;
            }
            case 2:{
                printf("2 : PUSH\n");
                PUSH(lineInfo, registers, variables, stack, &sp);
                //print all the stack
                for (int i = 0; i < sp; i++) {
                    printf("%d\n", stack[i]);
                }
                wait();
                pc++;
                break;
            }
            case 3:{
                printf("3 : POP\n");

                //print all the stack
                if (sp != 0) {
                    POP(lineInfo, stack, &sp, registers);
                    if (sp != 0) {
                        for (int i = 0; i < sp; i++) {
                            printf("%d\n", stack[i]);
                        }
                    }else{
                        printf("The stack is empty\n");
                    }
                } else{
                    printf("The stack is empty\n");
                }
                wait();
                pc++;
                break;
            }
            case 4:{
                printf("4 : AND\n");
                AND(lineInfo, registers, variables);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                wait();
                pc++;
                break;
            }
            case 5:{
                printf("5 : OR\n");
                OR(lineInfo, registers, variables);
                wait();
                pc++;
                break;
            }
            case 6:{
                printf("6 : NOT\n");
                NOT(lineInfo, registers);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                wait();
                pc++;
                break;
            }
            case 7:{
                printf("7 : ADD\n");
                ADD(lineInfo, registers, variables);
                wait();
                pc++;
                break;
            }
            case 8:{
                printf("8 : SUB\n");
                SUB(lineInfo, registers, variables);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                wait();
                pc++;
                break;
            }
            case 9:{
                printf("9 : DIV\n");
                DIV(lineInfo, registers, variables);
                wait();
                pc++;
                break;
            }
            case 10:{
                printf("10 : MUL\n");
                MUL(lineInfo, registers, variables);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                wait();
                pc++;
                break;
            }
            case 11:{
                printf("11 : MOD\n");
                MOD(lineInfo, registers, variables);
                wait();
                pc++;
                break;
            }
            case 12:{
                printf("12 : INC\n");
                INC(lineInfo, registers);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                wait();
                pc++;
                break;
            }
            case 13:{
                printf("13 : DEC\n");
                DEC(lineInfo, registers);
                wait();
                pc++;
                break;
            }
            case 14:{
                printf("14 : BEQ\n");
                printf("The value of the program counter is %d\n", pc);
                BEQ(lineInfo, registers, variables, &pc);
                printf("The new value of the program counter is %d\n", pc);
                wait();
                pc++;
                break;
            }
            case 15:{
                printf("15 : BNE");
                BNE(lineInfo, registers, variables, &pc);
                wait();
                pc++;
                break;
            }
            case 16:{
                printf("16 : BBG\n");
                printf("The value of the program counter is %d\n", pc);
                BBG(lineInfo, registers, variables, &pc);
                printf("The new value of the program counter is %d\n", pc);
                wait();
                pc++;
                break;
            }
            case 17:{
                printf("17 : BSM\n");
                BSM(lineInfo, registers, variables, &pc);
                wait();
                pc++;
                break;
            }
            case 18:{
                printf("18 : JMP\n");
                printf("The value of the program counter is %d\n", pc);
                JMP(lineInfo, &pc);
                printf("The new value of the program counter is %d\n", pc);
                wait();
                pc++;
                break;
            }
            case 19:{
                printf("19 : HLT\n");
                pc = line_program + 1;
                break;
            }
        }
    }
    printf("The program is finished\n");

    return 0;

}