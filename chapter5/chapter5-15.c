#include<stdio.h>
#include<math.h>
int main(){
    double high=10,low=-10;
    double mid,r;
    while(low<=high){
        mid=(high+low)/2;
        r=2*mid*mid*mid-4*mid*mid+3*mid-6;
        if(r>0){
            high=mid;
        }
        else if(r<0) low=mid;
        else
        {
            break;
        }
        
    }
    printf("result= %lf",mid);
    return 0;
}