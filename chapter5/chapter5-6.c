#include<stdio.h>
#include<math.h>
#define NUM 4
int main(){
    int result=0,r=1;
    for(int i=1;i<=NUM;i++){
        for(int j=1;j<=i;j++){
            r*=j;
        }
        result+=r;
        r=1;
    }
    printf("sum(20!)= %d",result);
    return 0;
}