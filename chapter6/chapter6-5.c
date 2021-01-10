#include<stdio.h>
int main(){
    int data[]={1,2,3,4,5,6,7,8,9,10};
    int i,temp,size=sizeof(data)/(sizeof(int));
    for(i=0;i<size/2;i++){
        temp=data[i];
        data[i]=data[size-1-i];
        data[size-1-i]=temp;
    }
    for(i=0;i<size;i++)printf("%d ",data[i]);
    return 0;
}