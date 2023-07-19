#include <stdio.h>

int main() {
    int aux4;
    int x, y;
    scanf("%d %d", &x, &y);

    int quantidade1 = 0;
    int quantidade2 =0;
    for (int i = 1; i <=x; i++) {
        if (x % i == 0) {
            quantidade1++;
        }
    }
    for (int i = 1; i <=y; i++) {
        if (y % i == 0) {
            quantidade2++;
        }
    }
    
    int maior, menor;
    if (quantidade1 > quantidade2) {
        maior = x;
        menor = y;
    } 
    else if(quantidade1 < quantidade2) {
        maior = y;
        menor = x;
    }
    else 
        if(x>y){
            aux4=y;
            y=x;
            x=aux4;
        }


    int resto;
    while (menor != 0) {
        resto = maior % menor;
        maior = menor;
        menor = resto;
    }
    int mdc=maior;

    
    int quantidade_x = quantidade1;
    int quantidade_y = quantidade2;

    
    int a, b;
    if (quantidade_x >= quantidade_y) {
        a = x;
        b=  y;
    } 
    else {
        a = y;
        b = x;
    }
    int quantidade3=0;
    int flag=0;
    
    for (int i = 2; i * i <= b; i++) {
        if (b % i == 0) {
            flag=1;
        }
    }
    if (b<2) {
        flag=1;
    }
    if(b==2){
        flag=0;
    }
    if (flag==0) {
        if(b==y){     
            b = x-1 ;
        }
        if(b==x){
            b=y-1;
        }
            quantidade3=2;
            while (quantidade3 == 2) {
                quantidade3=0;
                for (int i = 1; i <=b; i++) {
                    if (b % i == 0) {
                        quantidade3++;
                    }
                }
                if(quantidade3==2){
                    b--;
                }
                
            }
            int numa=b-1;
            int flag2=0;
            quantidade3=2;
            while(numa>y&&quantidade3==2){
                quantidade3=0;
                for (int i = 1; i <=numa; i++) {
                    if (numa % i == 0) {
                        quantidade3++;
                    }
                }
                if(quantidade3==2){
                    numa--;
                    flag2==1;
                }
            }
            if(flag2==1){
                b=numa;
            }
    }
    int aux;
    if(a<b){
        aux=a;
        a=b;
        b=aux;
    }
    printf("%d %d %d\n", a, b, mdc);

    return 0;
}
