/*
*求三位数的水仙花数
*/
#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    for(int i=100;i<1000;i++){
        a=i%10;//个位数
        b=(i/10)%10;//十位数
        c=i/100;//百位数
        if(pow(a,3)+pow(b,3)+pow(c,3)==i)
            printf("%d\n",i);
    }
    return 0;
}