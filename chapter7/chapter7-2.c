#include<stdio.h>
#include<math.h>
void MoreThanZero(double a,double b,double c);
void EqualZero(double a,double b,double c);
void LowerThanZero(double a,double b,double c);
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(b*b-4*a*c>0)MoreThanZero(a,b,c);
    else if(b*b-4*a*c==0)EqualZero(a,b,c);
    else LowerThanZero(a,b,c);
    return 0;
}
void MoreThanZero(double a,double b,double c){
    double value=pow(b*b-4*a*c,0.5);
    printf("X1 = %f\n",(-b+value)/(2*a));
    printf("X2 = %f\n",(-b-value)/(2*a));
}
void EqualZero(double a,double b,double c){
    printf("X = %lf\n",(-b)/(2*a));
}
void LowerThanZero(double a,double b,double c){
    printf("There is no root");
}