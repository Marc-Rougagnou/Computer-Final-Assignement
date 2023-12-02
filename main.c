//
// Created by Marc on 02/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //Readind of the test.txt file
    FILE* fichier = fopen("..\\test.txt", "r");
    if (fichier != NULL){
        printf("File opened\n");

        //Read by pack of 32 characters
        char chaine1[32] = "";
        while (fread(chaine1, 32, 1, fichier) != 0) {
            printf("%s\n", chaine1);

            //Retrive 5 first characters of the pack
            char chaine2[5] = "";
            for (int i = 0; i < 5; i++) {
                printf("%c\n", chaine1[i]);
                chaine2[i] = chaine1[i];
            }
            printf("%s\n", chaine2);

            //Convert chaine2 which is binary to decimal
            int decimal = 0;
            for (int i = 0; i < 5; i++) {
                decimal += (chaine2[i] - '0') * (1 << (4 - i));
            }
            printf("%d\n\n", decimal);

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
    }
    else{
        printf("Error while opening the file\n");
    }
    return 0;
}
