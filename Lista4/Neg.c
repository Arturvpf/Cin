#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    
    int n;
    int tamsenha=0;

    scanf("%d",&n);

    char senha[n][100];
    for(int i=0;i<n;i++){
        scanf("%s",senha[i]);
        
        for(int j=0;j<strlen(senha[i]);j++){
            if(senha[i][j]<48||(senha[i][j]>57&&senha[i][j]<65)||senha[i][j]>90){
                printf("Alguma senha eh invalida!"); exit(1);
            }   
            if(senha[i][j]=='0'){
                senha[i][j]='6';
            }
            else if(senha[i][j]=='1'){
                senha[i][j]='7';
            }
            else if(senha[i][j]=='2'){
                senha[i][j]='9';
            }
            else if(senha[i][j]=='3'){
                senha[i][j]='8';
            }
            else if(senha[i][j]=='4'){
                senha[i][j]='A';
            }
            else if(senha[i][j]=='5'){
                senha[i][j]='2';
            }
            else if(senha[i][j]=='6'){
                senha[i][j]='B';
            }
            else if(senha[i][j]=='7'){
                senha[i][j]='F';
            }
            else if(senha[i][j]=='8'){
                senha[i][j]='1';
            }
            else if(senha[i][j]=='9'){
                senha[i][j]='C';
            }
            else if(senha[i][j]=='A'){
                senha[i][j]='0';
            }
            else if(senha[i][j]=='B'){
                senha[i][j]='D';
            }
            else if(senha[i][j]=='C'){
                senha[i][j]='E';
            }
            else if(senha[i][j]=='D'){
                senha[i][j]='3';
            }
            else if(senha[i][j]=='E'){
                senha[i][j]='5';
            }
            else if(senha[i][j]=='F'){
                senha[i][j]='4';
            }
        }
        tamsenha+=strlen(senha[i]);
    }
    for(int i=0;i<n;i++){
    printf("-");
    printf("%s",senha[i]);
    }
    printf(" %d",tamsenha);

}