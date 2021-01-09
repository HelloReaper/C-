#include<stdio.h>
#include<math.h>
int main(){
    int num[100]={0};
    int y=0,k=0;
    for(int i=2;i<=1000;i++){
        //printf("\n%d= ",i);
        for(int j=1;j<i;j++){
            if(i%j==0){
                y+=j;
                num[k++]=j;
                //printf("%d ",j);
            }
        }
        k=0;
        if(y==i){//satisfy condition,then print
            printf("%d its factors are ",i);
            for(int t=0;num[t]!=0;t++){
                printf("%d ",num[t]);
                num[t]=0;//clear num[]
            }
            printf("\n");
        }
        else//clear num[]
        {
            int p=0;
            while(num[p]){num[p++]=0;}
        }
        y=0;
    }
    return 0;
}