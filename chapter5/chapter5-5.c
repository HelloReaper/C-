//求Sn=a+aa+aaa+aaaa+n个a的值，其中a是一个数字，n表示a的位数，n由键盘输入
#include<stdio.h>
#include <math.h>
int main(){
    int a=0,n=0,result=0;
    scanf("%d%d",&a,&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            result+=pow(10,j)*a;
        }
    }
    printf("result= %d ",result);
    return 0;
}