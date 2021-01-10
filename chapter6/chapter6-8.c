#include<stdio.h>
int MaxRow(int data[][5],int row){
    int max=data[row][0];
    int column=0;
    for(int i=0;i<5;i++){
        if(max<data[row][i]){
            max=data[row][i];
            column=i;
        }
    }
    return column;
}

int MinColumn(int data[][5],int column){
    int min=data[0][column];
    int row=0;
    for(int i=0;i<5;i++){
        if(min>data[i][column]){
            min=data[i][column];
            row=i;
        }
    }
    return row;
}

int main(){
    int data[5][5]={6,3,15,6,7,
                    5,4,13,1,2,
                    8,7,9,4,0,
                    9,8,15,2,4,
                    7,4,16,1,3};
    int point=0,row,column;
    for(int i=0;i<5;i++){
        column=MaxRow(data,i);
        row=MinColumn(data,column);
        if(row==i){
            point++;
            printf("The point is data[%d][%d] = %d",row,column,data[row][column]);
        }
    }
    if(!point)printf("The point doesn't exist!!");
    return 0;
}