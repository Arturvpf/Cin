#include <stdio.h>
#include<stdlib.h>

float maior2(float num1,float num2){
    float maior;
    if(num1>num2)maior=num1;
    else maior=num2;
    return maior;
}
void printmaior(float x){
    printf("Maior=%f",x);
}
int main(){
    float x, y,z, maior;
    printf("Nums");
    scanf("%f %f %f", &x,&y,&z);
    printmaior(maior2(maior2(x,y),z));
    

}