#include<stdio.h>
#include<stdlib.h>

int main(){
    float a;
    float b;
    float c;
    float temp;

    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%f %f %f",&a,&b,&c);

    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }
    if(a<c){
        temp=a;
        a=c;
        c=temp;
    }
    if(b<c){
        temp=b;
        b=c;
        c=temp;
    }

    if(c<=0||b+c<a)
        printf("Not a triangle.\n");
    else if(a==b&&b==c)
        printf("Equilateral.\n");
    else if(a==b||b==c)
        printf("Isosceles.\n");
    else
        printf("Scalene.\n");
    return EXIT_SUCCESS;
}
