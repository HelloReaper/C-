#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp=fopen("chapter6-12.txt","r");
    if(fp==NULL){
        printf("chapter6-12.txt open failed!");
        exit(0);
    }
    char str;
    while((str=fgetc(fp))!=EOF){
        putchar(str);printf("->");
        if(str>='a'&&str<='z')putchar(219-str);
        else if(str>='A'&&str<='Z')putchar(155-str);
        printf("\n");
    }
    fclose(fp);
    return 0;
}