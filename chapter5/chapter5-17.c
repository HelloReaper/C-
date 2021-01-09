#include<stdio.h>
#include<math.h>
int Find(int Data[][3],int h){//在第Data[h][]行中找出唯一一个值为1的列，返回列号，否则返回-1
    int x=0,mark=-1;
    for(int i=0;i<3;i++){
        x+=Data[h][i];//计算改行所有列之和
        if(Data[h][i]==1)mark=i;//值为1的列号赋值给mark
    }
    if(x>1)return -1;//不是只有一个1的情况
    else
    {
        return mark;
    }
}

int main(){
    char J[3]={'A','B','C'};
    char Y[3]={'X','Y','Z'};
    int Data[3][3]={0,1,1,1,1,1,0,1,0};//由题目条件得出的匹配数组，行是甲队，列是乙队
    int r=0,x,i,j;
    while(r<3){
        for(i=0;i<3;i++){
            x=Find(Data,i);//找出满足条件的对手
            if(x>=0){
                printf("%c -> %c\n",J[i],Y[x]);//将满足条件的人员匹配输出
                for(j=0;j<3;j++){//将Data的x列清零，相当于减少甲队中未匹配人员的可选项减少
                    Data[j][x]=0;
                }
                r++;
            }
        }
    }
    return 0;
}