//
// Created by Marc on 06/12/2023.
//

#include "display.h"



void display_register(int registers[]){//display all the registers
    printf("Registers: \n");
    for (int i = 0; i < 4; ++i) {
        if(registers[i] != -1){
            printf("t%d: %d\n", i, registers[i]);
        }
    }
    printf("\n");
}


void display_pc(int pc){//display the program counter
    printf("Program counter: %d\n\n", pc);
}


void display_stack(int stack[],int sp){//display the stack
    if (sp == 0){
        printf("The stack is empty");
    }
    else{
        printf("Stack: \n");
        for (int i = 0; i < sp; ++i) {
            printf("%d\n", stack[i]);
        }
    }
    printf("\n");
}

void display_variables(int variables[]){//display all the variables
    int cnt = 0;
    for(int i = 0; i < 26; ++i){
        if(variables[i] != -1){
            cnt++;
        }
    }
    if(cnt == 0){
        printf("There is no variables\n");
        return;
    }
    else{
        printf("Variables: \n");
        for (int i = 0; i < 26; ++i) {
            if(variables[i] != -1){
                printf("%c: %d \n", (char)i+65, variables[i]);
            }
        }
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
            printf("%c",(char)lineInfo.value1+65);
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
            printf(", %c",(char)lineInfo.value2+65);
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

