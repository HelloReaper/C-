#include<stdio.h>
int main(){
    int data[]={1,3,5,7,4,6,2,9,8,10};
    int min=data[0],temp,r=0;
    for(int i=0;i<10;i++){
        min=data[i];r=i;
        for(int j=i+1;j<10;j++){
            if(data[j]<min){
                r=j;
                min=data[j];
            }
        }
        data[r]=data[i];
        data[i]=min;
    }
    for(int i=0;i<10;i++){
        printf("%d ",data[i]);
    }
    return 0;
}