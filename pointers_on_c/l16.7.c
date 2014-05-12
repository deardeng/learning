#include<stdlib.h>
#include<stdio.h>

int frequency2[2];
int frequency3[3];
int frequency4[4];
int frequency5[5];
int frequency6[6];
int frequency7[7];
int frequency8[8];
int frequency9[9];
int frequency10[10];

int cycle2[2][2];
int cycle3[3][3];
int cycle4[4][4];
int cycle5[5][5];
int cycle6[6][6];
int cycle7[7][7];
int cycle8[8][8];
int cycle9[9][9];
int cycle10[10][10];

#define CHECK(number,f_table,c_table)           \
        remainder=x%number;                     \
        f_table[remainder]+=1;                  \
        c_table[remainder][last_x%number]+=1    

#define PRINT_F(number,f_table)                 \
        printf("\nFrequency of random numbers modulo %d\n\t",   \
                number);                        \
        for(i=0;i<number;i+=1)                  \
            printf(" %5d",f_table[i]);          \
        printf("\n")                            

#define PRINT_C(number,c_table)                \
            printf("\nCyclic frequency of numbers modulo %d\n", \
                    number);                    \
        for(i=0;i<number;i++){                  \
            printf("\t");                       \
            for(j=0;j<number;j++)               \
                printf(" %5d",c_table[i][j]);   \
            printf("\n");                       \
        }                                       

int main(int ac,char **av){
    int i,j,x,last_x,remainder;

    if(ac>1)
        srand(atoi(av[1]));
    last_x=rand();

    for(i=0;i<10000;i++){
        x=rand();
        CHECK(2,frequency2,cycle2);
        CHECK(3,frequency3,cycle3);
        CHECK(4,frequency4,cycle4);
        CHECK(5,frequency5,cycle5);
        CHECK(6,frequency6,cycle6);
        CHECK(7,frequency7,cycle7);
        CHECK(8,frequency8,cycle8);
        CHECK(9,frequency9,cycle9);
        CHECK(10,frequency10,cycle10);
        last_x=x;
    }

    PRINT_F(2,frequency2);
    PRINT_F(3,frequency3);
    PRINT_F(4,frequency4);
    PRINT_F(5,frequency5);
    PRINT_F(6,frequency6);
    PRINT_F(7,frequency7);
    PRINT_F(8,frequency8);
    PRINT_F(9,frequency9);
    PRINT_F(10,frequency10);

    PRINT_C(2,cycle2);
    PRINT_C(3,cycle3);
    PRINT_C(4,cycle4);
    PRINT_C(5,cycle5);
    PRINT_C(6,cycle6);
    PRINT_C(7,cycle7);
    PRINT_C(8,cycle8);
    PRINT_C(9,cycle9);
    PRINT_C(10,cycle10);

    return EXIT_SUCCESS;
}
