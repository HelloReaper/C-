#include<stdio.h>
int main(){
    double length=100.0,ten=0,h=100.0;
    for(int i=0;i<10;i++){
        h/=2;
        length+=h*2;
    }
    printf("all go through %lf meter, the tenth height is %lf meter",length,h);
    return 0;
}