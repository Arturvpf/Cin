#include <stdio.h>
#include<stdlib.h>

float maior2(float num1,float num2){
    float maior;
    if(num1>num2)maior=num1;
    else maior=num2;
    return maior;
}
int main(){
    float x, y, maior;
    scanf("%f %f", &x,&y);
    maior=maior2(x,y);
    printf("%f",maior);
    

}