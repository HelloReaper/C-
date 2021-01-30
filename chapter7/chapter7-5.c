#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10000
#define NUM 5
#define STUDENTS 10
void Reverse(char str[]);
char *StrConnect(char *a,char *b);
void TransYuanYin(char a[],char b[]);
void PrintFigure(void);
void CaculateString(char *str);
void PrintLongestStr(char *str);
void BubbleSort(char *str);
double NewDun(double x,double a,double b,double c,double d);
double Lerangdeduo(double x,int n);
double StudentAverage(double student[],int n);
double ProjectAverage(double project[],int n);
void HighestStudentProject(double record[][NUM],int *std,int *course);
double AverageFangCha(double student[][NUM]);
int TranstoOct(char *s);
void Int_to_Str(int num,char *s);
void TransIntStr(int num,char *s);
int CaculateDate(int year,int month,int day);
int main(){
    //chapter7-5
    //char str[MAX],*s;
    //int i=0,m=0;
    //scanf("%s",str);
    //Reverse(str);
    //chapter7-6
    /*char str[]="abcd",s[]="123";
    puts(StrConnect(str,s));
    */
    //chapter7-7
    /*char str[]="hello,my name is your father!",s[MAX];
    TransYuanYin(str,s);
    puts(s);
    */
    //chapter7-8
    //PrintFigure();
    //chapter7-9
    //CaculateString("123456  oneTwo !!!!!");
    //chapter7-10
    //PrintLongestStr("helloeveryone! 123 456 78995544 123 adsas");
    //chapter7-11
    //char s[]="2abgc211";
    //BubbleSort(s);
    ///chapter7-12
    //printf("x= %lf",NewDun(1,1,2,3,4));
    //chapter7-13
    //printf("%lf",Lerangdeduo(1,10));
    //chapter7-14
    //chapter7-16
    //char s[8];
    //printf("%d",TranstoOct(s));
    //chapter7-17
    /*char String[10000];
    int num;
    scanf("%d",&num);
    TransIntStr(num,String);
    printf("%s",String);
    */
   //chapter7-18
   printf("%d ",CaculateDate(2021,3,1));

    return 0;
}
void Reverse(char str[]){
    char s[MAX];
    char *st=s;
    int i=0;
    int m=strlen(str)/sizeof(char);
    while(str[i]!='\0'){
        s[i]=str[m-i-1];
        i++;
    }
    i=0;
    while(s[i]!='\0'){
        str[i]=s[i];
        i++;
    }
}
char *StrConnect(char a[],char b[]){
    int la=strlen(a)/sizeof(char),lb=strlen(b)/sizeof(char);
    char *new=(char*)calloc(la+lb,sizeof(char));
    for(int i=0;i<la+lb;i++){
        if(i<la)new[i]=a[i];
        else
        {
            new[i]=b[i-la];
        }
    }
    return new;
}
void TransYuanYin(char a[],char b[]){
    int i=0,j=0;
    while(a[i]!='\0'){
        switch (a[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            b[j++]=a[i];
            break;
        }
        i++;
    }
}
void PrintFigure(void){
    char c;
    while((c=getchar())!='\n')printf("%c ",c);
}

void CaculateString(char *str){
    int letter=0,number=0,space=0,others=0;
    int i=0;
    char s=*str;
    while((s=*str++)!='\0'){
        if(s>='A'&&s<='Z'||s>='a'&&s<='z')letter++;
        else if(s>='0'&&s<='9')number++;
        else if(s==' ')space++;
        else others++;
    }
    printf("Letters = %d , Numbers = %d , Space = %d , Others = %d",letter,number,space,others);
}

void PrintLongestStr(char *str){
    int i=0,length=0,maxlength=0;
    char s,*max;
    while((s=*str++)!='\0'){
        if(s!=' ')length++;
        else
        {
            if(length>=maxlength){
                maxlength=length;
                max=str-maxlength-1;
            }
            length=0;
        }
    }
    printf("max Length is ");
    while (*max!=' ')
    {
        putchar(*max++);
    }
    
}

void BubbleSort(char *str){
    int low=0,high=0,flag=0;
    char *s=str,temp=' ';
    while(*s++!='\0')high++;
    for(int i=0;i<high;i++){
        flag=0;
        for(int j=high-1;j>0;j--){
            if(str[j]<str[j-1]){
                temp=*(str+j);
                *(str+j)=*(str+j-1);
                *(str+j-1)=temp;
                flag=1;
            }
        }
        if(flag==0)break;   
    }
    printf("%s \n",str);
}

double NewDun(double x,double a,double b,double c,double d){
    double x1=0;
    while(fabs(x1-x)>pow(10,-5)){
        x1=x-(a*x*x*x+b*x*x+c*x+d)/(a*x*x+b*x+c);
        x=x1;
    }
    return x1;
}

double Lerangdeduo(double x,int n){
    if(n==0)return 1;
    else if(n==1)return x;
    return ((2*n-1)*x-Lerangdeduo(x,n-1)-(n-1)*Lerangdeduo(x,n-2))/n;
}

double StudentAverage(double student[],int n){
    double result=0.0;
    for(int i=0;i<n;i++){
        result+=student[i];
    }
    result=result/n;
    return result;
}

double ProjectAverage(double project[],int n){
    double result=0.0;
    for(int i=0;i<n;i++){
        result+=project[i];
    }
    result=result/n;
    return result;
}
void HighestStudentProject(double record[][NUM],int *std,int *course){
    double max=0;
    for(int i=0;i<STUDENTS;i++){
        for(int j=0;j<NUM;j++)
        {
            if(max<record[i][j]){
                *std=i;
                *course=j;
            }
        }
    }
}

double AverageFangCha(double student[][NUM]){
    double sum=0,sum2=0;
    for(int i=0;i<NUM;i++){
        sum2+=pow(StudentAverage(student[i],NUM),2);
        sum+=StudentAverage(student[i],NUM);
    }
    return sum2/STUDENTS-pow(sum/STUDENTS,2);
}

int TranstoOct(char *s){
    scanf("%s",s);
    Reverse(s);
    int i=0;
    int result=0;
    while(s[i]!='\0'){
        if(s[i]>='A'&&s[i]<='Z')result+=(s[i]-55)*pow(16,i);
        else result+=(s[i]-48)*pow(16,i);
        i++;
    }
    return result;
}

void Int_to_Str(int num,char *s){
    char *str=s;
    if(num==0){
        return;
    }
    *s=(num%10+48);
    Int_to_Str(num/10,s+1);
}
void TransIntStr(int num,char *s){
    Int_to_Str(num,s);
    Reverse(s);
}

int CaculateDate(int year,int month,int day){
    int num=0;
    switch (month)
    {
    case 1:
        num=day;
        break;
    case 2:
        num=31+day;
        break;
    case 3:
        num=31+28+day;
        break;
    case 4:
        num=31+28+31+day;
        break;
    case 5:
        num=31+28+31+30+day;
        break;
    case 6:
        num=31+28+31+30+31+day;
        break;
    case 7:
        num=31+28+31+30+31+30+day;
        break;
    case 8:
        num=31+28+31+30+31+30+31+day;
        break;
    case 9:
        num=31+28+31+30+31+30+31+31+day;
        break;
    case 10:
        num=31+28+31+30+31+30+31+31+30+day;
        break;
    case 11:
        num=31+28+31+30+31+30+31+31+30+31+day;
        break;
    case 12:
        num=31+28+31+30+31+30+31+31+30+31+30+day;
        break;
    default:
        break;
    }
    if(((year%4==0)&&(year%100!=0))||year%400==0)//闰年
        num++;
    return num;
}