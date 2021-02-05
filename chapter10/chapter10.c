#include<stdio.h>
#include<stdlib.h>
#define NUM 5
struct Student{
    int number;
    char name[100];
    float Chinese;
    float Math;
    float English;
    float average;
};

void TransLowToBig(void);
void MergeInformation(char *A,char *B,char *C);
void StudentGrade(struct Student s[],int n);
void Average_Sort(struct Student s[],int n);
/*
chapter10-1:
1.什么是文件型指针？通过文件指针访问文件有什么好处？
指向文件信息区的指针变量简称为指向文件的指针变量。通过文件指针指向某一个文件的文件信息区（一个结构体变量），通过该文件信息区中的信息就能够访问文件，也就是
说，通过文件指针变量能够找到与他相关联的文件
2.对文件的打开和关闭的含义是什么？为什么要打开和关闭文件？
文件的打开是指为文件建立相应的信息区，用来存放有关文件的信息，和文件缓冲区，用来暂时存放输入输出的数据。
文件的关闭是指撤销文件信息区和文件缓冲区，使文件指针变量不再指向该文件
只有先打开文件，才能为文件建立文件信息区，然后访问文件。
不再使用文件后，为了防止文件被错误修改，应该关闭文件，撤销其文件信息区和文件缓冲区，使文件指针变量不再指向该文件。
*/


int main(){
    //chapter10-3
    //TransLowToBig();
    //chapter10-4
    //char A[]="A.txt",B[]="B.txt",C[]="C.txt";
    //MergeInformation(A,B,C);
    //chapter10-5
    struct Student std[NUM];
    StudentGrade(std,NUM);
    Average_Sort(std,NUM);

    return 0;
}
//从键盘输入一个字符串，将小写字母全部转换为大写字母，输入到文件test中保存
void TransLowToBig(void){
    char c;
    FILE *fp=fopen("test.txt","w");
    if(fp==NULL){
        printf("cannot open file!\n");
        exit(0);
    }
    while((c=getchar())!='\n'){
        if(c>='a'&&c<='z'){
            c=c-32;
        }
        putchar(c);
        fputc(c,fp);
    }
    fclose(fp);
}

//将两个磁盘文件中的信息合并，结果保存到C文件中
void MergeInformation(char *A,char *B,char *C){
    FILE *fa=fopen(A,"r");
    FILE *fb=fopen(B,"r");
    FILE *fc=fopen(C,"w");
    if(fa==NULL||fb==NULL||fc==NULL){
        printf("openfile failed\n");
        exit(0);
    }
    char c;
    c=fgetc(fa);
    while(c!=EOF){
        fputc(c,fc);
        c=fgetc(fa);
    }
    c=fgetc(fb);
    while(c!=EOF){
        fputc(c,fc);
        c=fgetc(fb);
    }
    fclose(fa);
    fclose(fb);
    fclose(fc);
}
//5个学生的三门成绩键盘输入，计算平均成绩后存放与文件stud中
void StudentGrade(struct Student s[],int n){
    FILE *fp=fopen("stud.txt","w");
    if(fp==NULL){
         printf("openfile failed\n");
        exit(0);
    }
    for(int i=0;i<n;i++){
        scanf("%d%s%f%f%f",&s[i].number,s[i].name,&s[i].Chinese,&s[i].Math,&s[i].English);
        s[i].average=(s[i].Chinese+s[i].Math+s[i].English)/3;
        fprintf(fp,"%d %s %6.2f %6.2f %6.2f %6.2f",s[i].number,s[i].name,s[i].Chinese,s[i].Math,s[i].English,s[i].average);
        fputc('\n',fp);
    }
    fclose(fp);
}
//按平均分排序输出到文件stu_sort中,使用冒泡排序
void Average_Sort(struct Student s[],int n){
    int i=0,flag=0,j=0;
    FILE *fp=fopen("std_sort.txt","w");
    struct Student temp;
    for(i=0;i<n;i++){
        flag=0;
        for(j=n-1;j>i;j--){
            if(s[j].average<s[j-1].average){
                temp=s[j];
                s[j]=s[j-1];
                s[j-1]=temp;
                flag=1;
            }
        }
        if(flag==0)break;
    }
    for(i=0;i<n;i++){
        fprintf(fp,"%d %s %6.2f %6.2f %6.2f %6.2f",s[i].number,s[i].name,s[i].Chinese,s[i].Math,s[i].English,s[i].average);
        fputc('\n',fp);
    }
    fclose(fp);
}
