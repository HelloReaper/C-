//汉罗塔递归算法
#include<stdio.h>
void move(char a,char b);
void Hanoi(int n,char one,char two,char three);
int main(){
    int n;
    printf("please input the number of plates:");
    scanf("%d",&n);
    printf("the move steps are:\n");
    Hanoi(n,'A','B','C');
    return 0;
}
void move(char a,char b){
    printf("%c-->%c\n",a,b);
}
void Hanoi(int n,char one,char two,char three){
    if(n==1)move(one,three);
    else
    {
        Hanoi(n-1,one,three,two);
        move(one,three);
        Hanoi(n-1,two,one,three);
    }
}