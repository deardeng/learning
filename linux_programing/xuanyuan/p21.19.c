#include <stdio.h>

int function(int data[],int length){
    int currentAxis;
    int currentNum = 0;
    int i;
    for(i=0;i<length;i++){
        if(currentNum == 0){
            currentAxis = data[i];
            currentNum = 1;
        }
        else{
            if(currentAxis == data[i])
                currentNum++;
            else
                currentNum--;
        }
    }
    return currentAxis;
}

int main(){
    int data[] = {2,2,2,1,3};
    int axis = function(data,5);
    printf("%d\n",axis);
    return 0;
}
