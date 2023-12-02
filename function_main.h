//
// Created by Marc on 02/12/2023.
//

#ifndef COMPUTER_FINAL_ASSIGNEMENT_FUNCTION_MAIN_H
#define COMPUTER_FINAL_ASSIGNEMENT_FUNCTION_MAIN_H
typedef struct {
    char *line;//line of the file
    int operation;//operation associated to the line
    int type1; //0 for register / 1 for variable / 2 for constant
    int value1; //place in the table of the register or variable or the value of the constant
    int type2; //same as type1
    int value2; //same as value1
    int type3; //same as type1
    int value3; //same as value1
} operationInfo;
operationInfo giveInfoLine (char*);
#endif //COMPUTER_FINAL_ASSIGNEMENT_FUNCTION_MAIN_H
