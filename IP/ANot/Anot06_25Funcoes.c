#include <stdio.h>
#include<stdlib.h>

void swap(float *x,float *y){
	float t=*x;
	*x=*y;
	*y=t;
}
int main(){
	float x,y;
	scanf("%f %f", &x,&y);
	swap(&x,&y);
	printf("%f %f",x,y);
}