#include<stdio.h>
#include<stdlib.h>
#define NUM 100
#define ROW 3
void ThreeIntAndStr(void);
void BubbleSort(int data[],int n);
int CompareString(char *a,char *b);
void StringSort(char *data[],int n);
void InputTenNumber(int *data);
void Process(int *data,int n);
void PrintTenNumber(int *data,int n);
void DisgustNumber(int *data,int n,int m);
int QuitNumberThree(int people[],int n);
int StrLength(char *s);
void CopyMString(char *a,int m,char *b);
void Caculate(char *s,int *Big,int *small,int *space,int *num,int *other);
void TransPosition(int data[][3]);
void *new(int n);
void free(void *p);
int main(){
    //chapter8-1 AND chapter8-2
    //ThreeIntAndStr();
    //chapter8-3
    /*int data[10];
    InputTenNumber(data);
    Process(data,10);
    PrintTenNumber(data,10);*/
    //chapter8-4
    /*int data[]={1,2,3,4,5,6,7,8,9,10};
    DisgustNumber(data,sizeof(data)/sizeof(int),3);
    PrintTenNumber(data,sizeof(data)/sizeof(int));*/
    //chapter8-5
    int data[10]={1};
    printf("%d ",QuitNumberThree(data,10));
    
    //chapter8-6
    //char str[]="Test";
    //printf("%d",StrLength(str));
    //chapter8-7
    //char a[]="hello world",b[100];
    //CopyMString(a,2,b);
    //printf("%s",b);
    //chapter8-8
    /*char *s="123 hello WORLD!!!!";
    int big=0,small=0,space=0,num=0,other=0;
    Caculate(s,&big,&small,&space,&num,&other);
    printf("%d %d %d %d %d",big,small,space,num,other);*/
    //chapter8-9
    /*
    int data[3][3]={1,2,3,4,5,6,7,8,9};
    TransPosition(data);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           printf("%d ",data[i][j]);
        }
        printf("\n");
    }*/
    //chapter8-19
    /*char *s=new(10*sizeof(char));
    char a[10]="test";
    int i=0;
    while (*(a+i)!='\0')
    {
        s[i]=a[i];
        i++;
    }
    printf("new = %s \n",s);
    free(s);
    printf("free = %s",s);
    */
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
//字符串排序函数,实际上就是冒泡
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
//输入10个数
void InputTenNumber(int *data){
    for(int i=0;i<10;i++){
        scanf("%d",data+i);
    }
}
//对10个数进行处理
void Process(int *data,int n){
    int min=*data,max=*data;
    int Min=0,Max=0;
    for(int i=0;i<n;i++){
        if(min>*(data+i)){
            Min=i;
            min=*(data+i);
        }
        if(max<*(data+i)){
            Max=i;
            max=*(data+i);
        }
    }
    *(data+Min)=*data;
    *data=min;
    if(max!=*(data+n-1)){
        *(data+Max)=*(data+n-1);
        *(data+n-1)=max;
    }
}
//输出10个数
void PrintTenNumber(int *data,int n){
    for(int i=0;i<10;i++){
        printf("%d ",*(data+i));
    }
}
//将n个数向后移动m个位置
void DisgustNumber(int *data,int n,int m){
    int *d=calloc(n,sizeof(int));
    int i;
    for(i=0;i<n;i++){
        *(d+i)=*(data+i);
    }
    for(i=n-m;i>0;i--){
        *(data+i-1+m)=*(data+i-1);
    }
    for(int i=0;i<m;i++){
        *(data+i)=*(d+n-m+i);
    }
}
//求退出3号后，最后留下的是原来的几号
int QuitNumberThree(int people[],int n){
    int i=0;
    int *p=people;
    for(i=0;i<n;i++)
    {
        *(people+i)=1;
    }
    int flag=n,j=0,m=3,x=0;//值为1的数组元素数m=3个数,用x来记录数了几次
    i=0;
    while(flag!=1){//如果剩余人数大于1，继续数
        while(x<m){
            if(*(p+j)==1){//值为1的就是没有被淘汰的人
                j++;
                x++;
            }
            else if(*(p+j)==0){//值为0就是被淘汰了的，直接顺沿到下一个，x不记录此次
                j++;
            }
            if(x!=m)j=j%n;//没有数到3时，j可以正常加1，并且利用j%n循环到0，但是当已经数到3时，必须先置数组元素值为0，再利用j%n把j循环到0
        }
        m=3;
        x=0;
        *(p+j-1)=0;//数到3的元素淘汰，赋值为0。但是当已经数到3时，必须先置数组元素值为0，再利用j%n把j循环到0,不然j-1就变成-1了
        j=j%n;
        flag--;//剩余人数减一
    }
    i=0;
    while (*(people+i)!=1&&i<n)
    {
        i++;
    }
    return i;
}
//求字符串的长度
int StrLength(char *s){
    int l=0;
    while (*s++!='\0')l++;
    return l;
}
//把a字符串从第m个字符开始的全部字符复制为另一个字符串b
void CopyMString(char *a,int m,char *b){
    char *p=a+m-1;
    while(*p!='\0'){
        *b=*p;
        b++;
        p++;
    }
    *b='\0';
}

//计算一个字符串中的大写字母，小写字母，空格，数字等的字符数
void Caculate(char *s,int *Big,int *small,int *space,int *num,int *other){
    while(*s!='\0'){
        if(*s>='A'&&(*s<='Z'))(*Big)++;
        else if((*s>='a')&&(*s<='z'))(*small)++;
        else if((*s>='0')&&(*s<='9'))(*num)++;
        else if(*s==' ')(*space)++;
        else (*other)++;
        s=s+1;
    }
}
//转置3*3矩阵
void TransPosition(int data[][3]){
    int temp=0,i=0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<i;j++){
            temp=data[i][j];
            data[i][j]=data[j][i];
            data[j][i]=temp;
        }
    }
}

//编写一个函数new，new(n)表示分配n个字节的内存空间
void *new(int n){
    return malloc(n);
}
//写一个free，将new函数占用的空间释放，free(p)表示将p指向单元后的内存段释放
void free(void *p){
    realloc(p,0);
}