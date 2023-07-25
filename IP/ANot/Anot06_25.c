#include <stdio.h>

float media(float num1,float num2){
    return (num1+num2)/2;
}
int main(){
    float num1, num2, num3;
    scanf("%f %f",&num1,&num2);
    num3=media(num1,num2);
    printf("%f",num3);
}