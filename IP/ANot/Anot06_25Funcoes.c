#include <stdio.h>
#include<stdlib.h>

void read(float *num){
	printf("digite um numero\n");
	scanf("%f",num);//*num  num=&num1 scanf= num=&num1
}
float media2(float num1,float num2){
    return (num1+num2)/2;
}
int main(){
	float num1,num2;
	read(&num1);
	read(&num2);
	printf("%f",media2(num1,num2));
}