#include<stdio.h>
#include<stdlib.h>
#define NUM 100
#define ROW 3
void ThreeIntAndStr(void);
void BubbleSort(int data[],int n);
int CompareString(char *a,char *b);
void StringSort(char *data[],int n);
int main(){
    //chapter8-1 AND chapter8-2
    ThreeIntAndStr();

    return 0;
}
//chapter8-1 AND chapter8-2
void ThreeIntAndStr(void){
    int Interger[ROW];
    char str[3][NUM];
    scanf("%d%d%d",Interger,Interger+1,Interger+2);
    for(int i=0;i<ROW;i++){
        scanf("%s",(str+i));
    }
    char *data[ROW]={*str,*(str+1),*(str+2)};
    StringSort(data,ROW);
    BubbleSort(Interger,sizeof(Interger)/sizeof(int));
    for(int i=0;i<ROW;i++){
        printf("%d ",*(Interger+i));
        printf("%s ",*(data+i));
    }
}
//冒泡排序
void BubbleSort(int *data,int n){
    int temp=0,flag=0;
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(*(data+j)<*(data+j-1)){
                temp=*(data+j);
                *(data+j)=*(data+j-1);
                *(data+j-1)=temp;
            }
            flag=1;
        }
        if(flag==0)break;
    }
}
//字符串比较函数
int CompareString(char *a,char *b){
    int i=0;
    while(*(a+i)!='\0'&&*(b+i)!='\0'){
        if(*(a+i)<*(b+i)){
            return -1;
        }
        else if(*(a+i)>*(b+i)){
            return 1;
        }
        else i++;
    }
    if(*(a+i)=='\0'&&*(b+i)!='\0')return -1;
    else if(*(a+i)!='\0'&&*(b+i)=='\0')return 1;
    else return 0;
}
//字符串排序函数
void StringSort(char *data[],int n){
    char *temp;
    int flag=0;
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(CompareString(*(data+j),*(data+j-1))==-1){
                temp=*(data+j);
                *(data+j)=*(data+j-1);
                *(data+j-1)=temp;
                flag=1;
            }
        }
        if(flag==0)return;
    }
}