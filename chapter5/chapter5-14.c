/*
*牛顿迭代法Xn+1=Xn-f(Xn)/f'(Xn);
*/
#include<stdio.h>
#include<math.h>
int main(){
    double Xn=1.5;
    double Xn1=Xn-(2*Xn*Xn*Xn-4*Xn*Xn+3*Xn-6)/(6*Xn*Xn-8*Xn+3);
    while (fabs(Xn-Xn1)>pow(10,-5))
    {
        Xn=Xn1;
        Xn1=Xn-(2*Xn*Xn*Xn-4*Xn*Xn+3*Xn-6)/(6*Xn*Xn-8*Xn+3); 
    }
    printf("result is %lf",Xn1);
    return 0;
}