#include<stdio.h>
#define NUM 65535
int main(){
    char str[NUM];
    printf("input a line of characters:");
    gets(str);
    printf("\n%s\n",str);
    int i=0;
    int english=0,space=0,number=0,others=0;
    while(str[i]!='\0'){
        if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z')english++;
        else if (str[i]>='0'&&str[i]<='9')number++;
        else if(str[i]==' ')space++;
        else others++;
        i++;
    }
    printf("the numbers of english= %d , sapce= %d , number= %d , others= %d\n",english,space,number,others);
    return 0;
}