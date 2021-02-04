#include<stdio.h>
#include<stdlib.h>
struct Date{
    int year;
    int month;
    int day;
};
struct Student{
    int order;
    struct Student *next;
};
struct Std{
    int number;
    int grade;
    struct Std *next;
};
int CaculateDate(struct Date date);
int OrderThreeQuit(struct Student *std);
void LinkSort(struct Std *s);
struct Std *MergeLink(struct Std *a,struct Std *b);



int main(){
    //chapter9-1
    //struct Date date={2020,1,30};
    //printf("%d",CaculateDate(date));
    //chapter9-6
    struct Student *p=malloc(sizeof(struct Student)),*first;
    first=p;
    p->order=1;//编号从1开始，不同于chapter8
    for(int i=2;i<=13;i++){
        p->next=malloc(sizeof(struct Student));
        p->next->order=i;
        p=p->next;
    }
    p->next=first;
    printf("%d",OrderThreeQuit(first));
    return 0;
}



//计算日期是第几天
int CaculateDate(struct Date date){
    int num=0;
    switch (date.month)
    {
    case 1:
        num=date.day;
        break;
    case 2:
        num=31+date.day;
        break;
    case 3:
        num=31+28+date.day;
        break;
    case 4:
        num=31+28+31+date.day;
        break;
    case 5:
        num=31+28+31+30+date.day;
        break;
    case 6:
        num=31+28+31+30+31+date.day;
        break;
    case 7:
        num=31+28+31+30+31+30+date.day;
        break;
    case 8:
        num=31+28+31+30+31+30+31+date.day;
        break;
    case 9:
        num=31+28+31+30+31+30+31+31+date.day;
        break;
    case 10:
        num=31+28+31+30+31+30+31+31+30+date.day;
        break;
    case 11:
        num=31+28+31+30+31+30+31+31+30+31+date.day;
        break;
    case 12:
        num=31+28+31+30+31+30+31+31+30+31+30+date.day;
        break;
    default:
        break;
    }
    if(((date.year%4==0)&&(date.year%100!=0))||date.year%400==0)//闰年
        num++;
    return num;
}
//13个人数数，报到3的退出，求剩余人的序号
int OrderThreeQuit(struct Student *std){
    int i=0,x=1;
    struct Student *p=std,*temp;
    while (p->next!=p)
    {
        while(x<2){
            p=p->next;
            x=x+1;
        }
        temp=p->next;//temp指向数到3的人
        p->next=p->next->next;//链表调整
        free(temp);//淘汰数到3的人
        p=p->next;//从淘汰者的后一个开始下一轮数数
        x=1;
    }
    return p->order;
}
//链表排序
void LinkSort(struct Std *s){
    int flag=1;
    struct Std *p=s,*temp;
    while(flag){
        if(p->number>p->next->number){//第一个结点发生了交换
            s=p->next;
            temp=p->next;
            p->next=p->next->next;
            temp->next=p;
            flag=1;
        }
        else{
            p=p->next;
        }
        flag=0;
        //后续结点发生交换
        //本质上还是冒泡排序
        while(p!=NULL){
            if(p->number>p->next->number){
                temp=p->next;
                p->next=p->next->next;
                temp->next=p;
                flag=1;
            }
            else{
                p=p->next;
            }
        }
        p=s;
    }
}

struct Std *MergeLink(struct Std *a,struct Std *b){
    struct Std *p=a;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=b;
    LinkSort(a);
    p=a;
    while(p!=NULL){
        printf("%d ",p->number);
    }
    return a;
}
