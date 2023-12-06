//
// Created by Marc on 02/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function_main.h"
#include "odd_operations.h"

int main() {

    int registers[4] = {8, 7, 0, 14};//Registers t0 on 0 t1 on 1 t2 on 2 and t3 on 3
    //create a table 2 dimensions of char

    /*char **variables = malloc(32 * sizeof(char *));
    for (int i = 0; i < 26; i++) {
        variables[i] = malloc(2 * sizeof(char));
        variables[i][0] = (int) 'A' + i;// define the different variables and put 0 for the first number
        variables[i][1] = '0';
    }*/
    int variables[26];//define the different variables and put 0 for the first number
    for (int i = 0; i < 26; i++) {
        variables[i] = i;
    }

    //char stack[32] = {'0'};//create the stack
    int stack[32];//create the stack

    int pc = 0;//program counter
    int sp = 0;//stack pointer

    //Readind of the test.txt file
    FILE *fichier = fopen("..\\test.txt", "r");
    if (fichier != NULL) {
        printf("File opened\n");

        // Read by pack of 32 characters
        char chaine1[33];


        // Create a table 2 dimensions of char
        char **tabPC = malloc(32 * sizeof(char *));
        int j = 0;
        while (fread(chaine1, 32, 1, fichier) != 0) {

            tabPC[j]= malloc(33 * sizeof(char));
            chaine1[32] = '\0';
            strncpy(tabPC[j], chaine1,32);
            j++;
        }

        fclose(fichier);
        //printf tabPC
        /*for (int i = 0; i < 4; i++) {
            printf("%s\n", tabPC[i]);
        }*/

        operationInfo lineInfo = giveInfoLine(tabPC[0]);

        switch (lineInfo.operation) {
            case 0:{
                printf("0 : LDA\n");
                LDA(lineInfo, registers, variables);

                printf("register t%d have the value: %d\n", lineInfo.value1, registers[lineInfo.value1]);
                break;
            }
            case 1:{
                printf("1 : STR\n");
                break;
            }
            case 2:{
                printf("2 : PUSH\n");
                PUSH(lineInfo, registers, variables, stack, &sp);
                //print all the stack
                for (int i = 0; i < sp; i++) {
                    printf("%d\n", stack[i]);
                }
                break;
            }
            case 3:{
                printf("3 : POP\n");
                break;
            }
            case 4:{
                printf("4 : AND\n");
                AND(lineInfo, registers, variables);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);

                break;
            }
            case 5:{
                printf("5 : OR\n");
                break;
            }
            case 6:{
                printf("6 : NOT\n");
                NOT(lineInfo, registers);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                break;
            }
            case 7:{
                printf("7 : ADD\n");
                break;
            }
            case 8:{
                printf("8 : SUB\n");
                SUB(lineInfo, registers, variables);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                break;
            }
            case 9:{
                printf("9 : DIV\n");
                break;
            }
            case 10:{
                printf("10 : MUL\n");
                MUL(lineInfo, registers, variables);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                break;
            }
            case 11:{
                printf("11 : MOD\n");
                break;
            }
            case 12:{
                printf("12 : INC\n");
                INC(lineInfo, registers);
                printf("The new value of the register t%d is %d\n", lineInfo.value1, registers[lineInfo.value1]);
                break;
            }
            case 13:{
                printf("13 : DEC\n");
                break;
            }
            case 14:{
                printf("14 : BEQ\n");
                printf("The value of the program counter is %d\n", pc);
                BEQ(lineInfo, registers, variables, &pc);
                printf("The new value of the program counter is %d\n", pc);
                break;
            }
            case 15:{
                printf("15 : BNE");
                break;
            }
            case 16:{
                printf("16 : BBG\n");
                printf("The value of the program counter is %d\n", pc);
                BBG(lineInfo, registers, variables, &pc);
                printf("The new value of the program counter is %d\n", pc);
                break;
            }
            case 17:{
                printf("17 : BSM\n");
                break;
            }
            case 18:{
                printf("18 : JMP\n");
                break;
            }
            case 19:{
                printf("19 : HLT\n");
                break;
            }
        }


    } else {
        printf("Error opening the file\n");
    }
    return 0;

}


/*
        //Readind of the test.txt file
    FILE* fichier = fopen("..\\test.txt", "r");
    if (fichier != NULL){
        printf("File opened\n");

        //Read by pack of 32 characters
        char chaine1[32] = "";
        while (fread(chaine1, 32, 1, fichier) != 0) {
            //Retrive 5 first characters of the pack
            char chaine2[5] = "";
            for (int i = 0; i < 5; i++) {
                chaine2[i] = chaine1[i];
            }

            //Convert chaine2 which is binary to decimal
            int decimal = 0;
            for (int i = 0; i < 5; i++) {
                decimal += (chaine2[i] - '0') * (1 << (4 - i));
            }
        }
    }
    else{
        printf("Error while opening the file\n");
    }


            switch (decimal) {
                case 0:{
                    printf("0 : LDA\n");
                    break;
                }
                case 1:{
                    printf("1 : STR\n");
                    break;
                }
                case 2:{
                    printf("2 : PUSH\n");
                    break;
                }
                case 3:{
                    printf("3 : POP\n");
                    break;
                }
                case 4:{
                    printf("4 : AND\n");
                    break;
                }
                case 5:{
                    printf("5 : OR\n");
                    break;
                }
                case 6:{
                    printf("6 : NOT\n");
                    break;
                }
                case 7:{
                    printf("7 : ADD\n");
                    break;
                }
                case 8:{
                    printf("8 : SUB\n");
                    break;
                }
                case 9:{
                    printf("9 : DIV\n");
                    break;
                }
                case 10:{
                    printf("10 : MUL\n");
                    break;
                }
                case 11:{
                    printf("11 : MOD\n");
                    break;
                }
                case 12:{
                    printf("12 : INC\n");
                    break;
                }
                case 13:{
                    printf("13 : DEC\n");
                    break;
                }
                case 14:{
                    printf("14 : BEQ\n");
                    break;
                }
                case 15:{
                    printf("15 : BNE");
                    break;
                }
                case 16:{
                    printf("16 : BBG\n");
                    break;
                }
                case 17:{
                    printf("17 : BSM\n");
                    break;
                }
                case 18:{
                    printf("18 : JMP\n");
                    break;
                }
                case 19:{
                    printf("19 : HLT\n");
                    break;
                }
            }

        }
    }*/


