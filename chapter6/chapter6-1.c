#include<stdio.h>
#include<math.h>
int main(){
    int k,flag=0;
    for(int i=1;i<100;i++){
        k=sqrt(i);
        for(int j=2;j<=k;j++){
            if(i%j==0)flag=1;
        }
        if(flag==0)printf("%d \n",i);
        flag=0;
    }
    return 0;
}