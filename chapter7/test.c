#include<stdio.h>
void fun(int *data,int n){
    printf("%d \n",sizeof(data));
}
int main(){
    int data[]={1,2,3};
    printf("%d \n",sizeof(data));
    fun(data,3);
    printf("%d\n",sizeof(int));
    return 0;
}