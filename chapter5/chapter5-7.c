#include<stdio.h>
#include<math.h>
#define NUM 100
int main(){
    float result=0.0;
    for(int i=1;i<=NUM;i++){
        if(i<=10)result+=(float)1/i;
        if(i<=50)result+=i*i;
        result+=i;
    }
    printf("result= %f ",result);
    return 0;
}