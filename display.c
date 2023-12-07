//
// Created by Marc on 06/12/2023.
//

#include "display.h"



void display_register(int registers[]){//display all the registers
    printf("Register t0: %d\n", registers[0]);
    printf("Register t1: %d\n", registers[1]);
    printf("Register t2: %d\n", registers[2]);
    printf("Register t3: %d\n", registers[3]);
}


void display_pc(int pc){//display the program counter
    printf("Program counter: %d\n", pc);
}

void display_tabPC(char **tabPC){//display the array of all the lines of codes in binary
    printf("Table of program counter: \n");
    for (int i = 0; i < 32; ++i) {
        printf("%s\n", tabPC[i]);
    }
}


void display_sp(int sp){//display the stack pointer
    printf("Stack pointer: %d\n", sp);
}

void display_stack(int stack[],int sp){//display the stack
    printf("Stack: ");
    for (int i = 0; i < sp; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void display_variables(int variables[]){//display all the variables
    printf("Variables: ");
    for (int i = 0; i < 8; ++i) {
        printf("%d ", variables[i]);
    }
    printf("\n");
}


void display_line(operationInfo lineInfo){//display the line of code in assembly(not binary)
    switch (lineInfo.operation){
        case 0:{
            printf("LDA ");
            break;
        }
        case 1:{
            printf("STR ");
            break;
        }
        case 2:{
            printf("PUSH ");
            break;
        }
        case 3:{
            printf("POP ");
            break;
        }
        case 4:{
            printf("AND ");
            break;
        }
        case 5:{
            printf("OR ");
            break;
        }
        case 6:{
            printf("NOT ");
            break;
        }
        case 7:{
            printf("ADD ");
            break;
        }
        case 8:{
            printf("SUB ");
            break;
        }
        case 9:{
            printf("DIV ");
            break;
        }
        case 10:{
            printf("MUL ");
            break;
        }
        case 11:{
            printf("MOD ");
            break;
        }
        case 12:{
            printf("INC ");
            break;
        }
        case 13:{
            printf("DEC ");
            break;
        }
        case 14:{
            printf("BEQ ");
            break;
        }
        case 15:{
            printf("BNE ");
            break;
        }
        case 16:{
            printf("BBG ");
            break;
        }
        case 17:{
            printf("BSM ");
            break;
        }
        case 18:{
            printf("JMP ");
            printf("%d\n", lineInfo.label);
            return;
        }
        case 19:{
            printf("HLT ");
            break;
        }
    }
    switch (lineInfo.type1){
        case 0:{
            break;
        }
        case 1:{
            printf("t%d",lineInfo.value1);
            break;
        }
        case 2:{
            printf("%c",(char)lineInfo.var1+65);
            break;
        }
        case 3:{
            printf("$%d", lineInfo.value1);
            break;
        }
    }
    switch(lineInfo.type2){
        case 0:{
            break;
        }
        case 1:{

            printf(", t%d ",lineInfo.value2);
            break;
        }
        case 2:{
            printf(", %c",(char)lineInfo.var2+65);
            break;
        }
        case 3:{
            printf(", $%d", lineInfo.value2);
            break;
        }
    }
    switch(lineInfo.operation){
        case 15:{
            printf(", %d", lineInfo.label);
            break;
        }
        case 16:{
            printf(", %d", lineInfo.label);
            break;
        }
        case 17:{
            printf(", %d", lineInfo.label);
            break;
        }
        case 18:{
            printf(", %d", lineInfo.label);
            break;
        }

    }
    printf("\n");

}

