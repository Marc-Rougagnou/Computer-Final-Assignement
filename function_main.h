//
// Created by Marc on 02/12/2023.
//

#ifndef COMPUTER_FINAL_ASSIGNEMENT_FUNCTION_MAIN_H
#define COMPUTER_FINAL_ASSIGNEMENT_FUNCTION_MAIN_H
typedef struct {
    char *line;//line of the file in binary
    int operation;//operation associated to the line
    int type1; //1 for register / 2 for variable / 3 for constant / 0 is nothing
    int value1; //place in the table of the register or variable or the value of the constant
    int type2; //same as type1
    int value2; //same as value1
    int label;
    int var1;//nom de la variable --> numéro par rapport à sa place dans l'alphabet si type1 = 2
    int var2;//nom de la variable --> numéro par rapport à sa place dans l'alphabet si type2 = 2
} operationInfo;
operationInfo giveInfoLine (char*);
int type_register(char*, int);
int type_variable(char*, int);
int type_constant(char*, int);
int name_variable(char*, int);
int convert_dec(char*, int);
#endif //COMPUTER_FINAL_ASSIGNEMENT_FUNCTION_MAIN_H
