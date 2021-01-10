#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 80
int main(){
    FILE *fp=fopen("chapter6-10.txt","r");
    if( fp == NULL ){
        printf("Fail to open file!\n");
        exit(0);  //退出程序（结束程序）
    }
    char str;
    int big=0,samll=0,num=0,sapce=0,others=0;
    while((str=fgetc(fp))!=EOF){
        if(str>='0'&&str<='9')num++;
        else if(str>='A'&&str<='Z')big++;
        else if(str>='a'&&str<='z')samll++;
        else if(str==' ')sapce++;
        else others++;
        putchar(str);
    }
    printf("\nThe numbers of Capital = %d , lower = %d , numbers = %d , spaces = %d , others = %d ",big,samll,num,sapce,others);
    fclose(fp);
    return 0;
}