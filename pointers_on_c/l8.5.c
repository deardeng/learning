#include<stdio.h>

void matrix_multiply(int *m1,int *m2,register int *r,int x,int y,int z){

    register int *m1p;
    register int *m2p;
    register int k;
    int row;
    int column;

    for(row=0;row<x;row+=1){
        for(column=0;column<z;column+=1){
            m1p=m1+row*y;
            m2p=m2+column;
            *r=0;

            for(k=0;k<y;k+=1){
                *r+=*m1p**m2p;
                m1p+=1;
                m2p+=z;
            }
            r++;
        }
    }
}

int main(){
    int i,j;
    int s1[3][2]={
        {2,-6},
        {3,5},
        {1,-1}
    };
    int s2[2][4]={
        {4,-2,-4,-5},
        {-7,-3,6,7}
    };
    int s3[3][4];
    matrix_multiply(*s1,*s2,*s3,3,2,4);
    for(i=0;i<3;i++){
        for(j=0;j<4;j++)
            printf("%5d",s3[i][j]);
        printf("\n");
    }
    return 0;
}
