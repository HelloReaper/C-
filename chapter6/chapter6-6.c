//输出杨辉三角
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("%d\n",sizeof(int*));
    printf("please input lines: ");//指定输出行数
    scanf("%d",&n);
    int **data=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        data[i]=(int*)calloc(i+1,sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if((j==0)||(i==j)){
                data[i][j]=1;//第一列和对角线上的为1
            }
            else
            {
                data[i][j]=data[i-1][j-1]+data[i-1][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",data[i][j]);
        }
        free(data[i]);
        printf("\n");
    }
    free(data);
    return 0;
}