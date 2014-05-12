#include<stdio.h>
#include<stdarg.h>

int max_list(int first_arg,...){
    va_list var_arg;
    int max=0;

    if(first_arg>=0){
        int this_arg;
        max=first_arg;
        va_start(var_arg,first_arg);
        while((this_arg=va_arg(var_arg,int))>=0)
            if(this_arg>max)
                max=this_arg;
        va_end(var_arg);
    }
    return max;
}

int main(){
    printf("%d\n",max_list(10,20,30,-1));
    printf("%d\n",max_list(20,10,-1));
    printf("%d\n",max_list(10,-1));
    printf("%d\n",max_list(10));
}
