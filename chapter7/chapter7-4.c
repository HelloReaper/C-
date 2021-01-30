#include<stdio.h>
void Reverse(int data[][3]);
void print(int data[][3]);
int main(){
    int data[][3]={1,2,3,4,5,6,7,8,9};
    print(data);
    Reverse(data);
    print(data);
    return 0;
}
void Reverse(int data[][3]){
    int temp=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<i;j++){
            temp=data[i][j];
            data[i][j]=data[j][i];
            data[j][i]=temp;
        }
    }
}
void print(int data[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
}