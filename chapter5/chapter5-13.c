#include<stdio.h>
#include<math.h>
int main(){
    double a;
    scanf("%lf",&a);
    double Xn=a,Xn1=0.5*(Xn+a/Xn);
    //printf("xn+1= %lf",Xn1);
    while(fabs(Xn-Xn1)>pow(10,-5)){
        Xn=Xn1;
        Xn1=0.5*(Xn1+a/Xn1);
    }
    printf("result= %lf",Xn1);
    return 0;
}