#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char c='a';
    char *pc=&c;

    printf("A)Endereco de C:%p\nValor de  C :%c\n",&c,c); 
    printf("B)Endereco que pc armazena:%p\nValor que Pc aponta:%c\n",pc,*pc);
    printf("C)Endereço de pc%p\n",&pc);
    printf("D)Endereco do valor guardado no endereco apontado por pc:%p\nValor guardado no endereco de pc%p",&(*pc),*&pc);
    /* 
    o Endereco do valor guardado no endereco apontado por pc será o proprio endereco de C , ja que pc=&c apontando para o endereco de c,
    o valor que pc tem armazenado seria *pc=a ,o endereco que possui 'a' guardado seria pc, que aponta para o endereco de c. 
    o valor guardado no endereco de pc seria o proprio endereco de C, ja que &pc é o endereco do ponteiro e o valor que este
    endereco tem é &c.
    */



    return 0;
}