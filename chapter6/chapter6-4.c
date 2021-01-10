#include<stdio.h>
#include<stdlib.h>
int main(){
    int *data=(int*)calloc(10,sizeof(int));
    for(int i=0;i<10;i++)data[i]=i;
    int temp;
    scanf("%d",&temp);
    int j=0;
    while(temp>data[j]&&j<10)j++;printf("%d\n",j);
    int *new=(int *)calloc(11,sizeof(int));
    for(int i=0;i<j;i++)new[i]=data[i];
    new[j]=temp;
    for(int i=j;i<10;i++)new[i+1]=data[i];
    for(int i=0;i<11;i++)printf("%d ",new[i]);
    free(data);
    free(new);
    return 0;
}