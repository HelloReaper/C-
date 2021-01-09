#include<stdio.h>
#include<math.h>
int main(){
    int n1=1,n2=2,temp;
    double result=2/1;
    for(int i=1;i<20;i++){
        result+=(double)(n1+n2)/n2;
        temp=n2;
        n2=n1+n2;
        n1=temp;
    }
    printf("result = %lf",result);
    return 0;
}