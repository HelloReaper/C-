#include<stdio.h>
#include<math.h>
int max(int a,int b);
int min(int a,int b);
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("max = %d\n",max(a,b));
    printf("min = %d\n",min(a,b));
    return 0;
}
int max(int a,int b){
    int m=1;
    for(int i=1;i<=a&&i<=b;i++){
        if(a%i==0&&b%i==0){
            m=i;
        }
    }
    return m;
}
int min(int a,int b){
    for(int i=a>b?a:b;i<=a*b;i++){
        if(i%a==0&&i%b==0)
            return i;
    }
    return a*b;
}
