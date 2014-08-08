#include <stdio.h>

int rightMin[100];
int arr[100] = {7,10,2,6,19,12,32};
void smallLarge(int *arr,int *rightMin,int n){
    int i,leftMax,Min;
    rightMin[n-1] = arr[n -1];
    for(i=n-2;i>=0;--i){
        if(arr[i] < arr[i+1]){
            rightMin[i] = arr[i];
            if(Min < arr[i])
                rightMin[i] = Min;
        }
        else{
            rightMin[i] = rightMin[i+1];
            Min = rightMin[i];
        }
    }
    leftMax = 0x80000000;
    for(i=0;i<n;++i){
        if(arr[i] >= leftMax){
            leftMax = arr[i];
            if(leftMax == rightMin[i])
                printf("%d\n",leftMax);
        }
    }
}

int main(){
    smallLarge(arr,rightMin,7);
}
