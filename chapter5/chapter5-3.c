#include<stdio.h>
#include<math.h>
int main(){
    int m,n;
    printf("��������������m��n��");
    scanf("%d%d",&m,&n);
    int i,j;
    int max,min;
    for(i=1,j=1;i<=m&&j<=n;i++,j++)
    {
        if(m%i==0&&n%i==0){
            max=i;
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(i*n==j*m){
                min=i*n>min?min:i*n;
            }
        }
    }
    printf("���Լ��Ϊ��%d,  ��С������Ϊ��%d",max,min);
    return 0;
}