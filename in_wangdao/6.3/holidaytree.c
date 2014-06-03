#include<stdio.h>
int main(){
    int i,j,z,y;
    for(i=0;i<5;i++){
        for(j=0;j<9;j++){
            z=i;y=j;
            if(j==-i+4||j==i+4||j==i+2||j==-i+6||j==i){
                if((i==0&&j==0)||(i==1&&j==1)||(i==0&&j==2)||(i==0&&j==6))
                    putchar(' ');
                else
                    putchar('*');
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    for(i=0;i<3;i++){
        printf("    *\n");
    }
}
