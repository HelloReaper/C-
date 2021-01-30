#include<stdio.h>
int IsZhiShu(int a);
int main(){
    int num;
    scanf("%d",&num);
    if(IsZhiShu(num))printf("yes it is!");
    else printf("It isn't!");
    return 0;
}
int IsZhiShu(int a){
    for(int i=2;i<a;i++){
        if(a%i==0)return 0;
    }
    return 1;
}