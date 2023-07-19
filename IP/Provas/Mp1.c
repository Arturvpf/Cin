#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int N;

    //Interface de Usuario
    printf("Insira o tamanho da matriz quadrada\n");
    scanf("%d",&N);

        //checar se o tamanho da matriz condiz com a condição
        if(N<15){
            printf("entrada inválida, o tamanho da matriz deve ser superior ou igual a 15\n");
        }
        else{
            char MatrizCaca[N][N];  //caca palavra
            char palavra[N+1];      // a palavra terá no máximo o tamanho da matriz + caractere nulo
            int posx=0;             //posicao a ser sorteada
            int posy=0;             //posicao a ser sorteada
            int conflito=0;         //flag

            //*casos duas palavras se encontrem sortear denovo
            
            //preencher o caca palavras com '0' para facilitar a verificacao de alguma palavra que possa dar conflito
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    MatrizCaca[i][j]='0';
                }
            }
            //loop de armazenamento das palavras
            while(palavra[0] !=('.')){
                scanf("%s", palavra);
                if(palavra!='.'){
                    posx=rand()%(N-strlen(palavra));
                    posy=rand()%(N-strlen(palavra));

                    //sortear a direção
                    int direcao = rand()%8;              
                    conflito=1;

                    //armazena a palavra na matriz de acordo com a direção
                    while(conflito==1){

                        int contador=0;
                        conflito=0;     //uma flag

                        if(direcao==0){      //L
                            if((strlen(palavra)+posy)>(N-1)){  //caso saia dos limites, sortear denovo
                                while((strlen(palavra)+posy)>(N-1)){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));                    
                                }
                            }
                            for(int j=posy;j<(strlen(palavra)+posy);j++){
                                int i=posx;      //verificar se tem alguma palavra na posica
                                if(MatrizCaca[i][j]!='0'){
                                    conflito=1;      // sortear denovo a posicao
                                }
                            }
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int j=posy;j<(strlen(palavra)+posy);j++){
                                    int i=posx;      //verificar se tem alguma palavra na posica
                                    MatrizCaca[i][j]=palavra[contador];
                                    contador++;
                                }
                            }
                            if(conflito==1){
                            //sortear a posicao novamente
                            posx=rand()%(N-strlen(palavra));
                            posy=rand()%(N-strlen(palavra));

                            if((strlen(palavra)+posy)>(N-1)){  //caso saia dos limites, sortear denovo
                                while((strlen(palavra)+posy)>(N-1)){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));                    
                                }
                            } 
                        }
                        }
                        if(direcao==1){  //SE checar se sai dos limites para a diagonal
                        //checar se a palavra nao sai dos limites da matriz pela diagonal
                            if((strlen(palavra)+posy)>(N-1)||(strlen(palavra)+posx)>(N-1)){
                                while((strlen(palavra)+posy)>(N-1)||(strlen(palavra)+posx)>(N-1)){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            }
                            for(int i=posx;i<(strlen(palavra)+posx);i++){ //verificar se tem alguma palavra na posicao
                                for(int j=posy;j<(strlen(palavra)+posy);j++){
                                    if(MatrizCaca[i][j]!='0'){
                                        conflito=1;      // sortear denovo a posicao
                                    }
                                }
                            }
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int i=posx;i<(strlen(palavra)+posx);i++){
                                    for(int j=posy;j<(strlen(palavra)+posy);j++){
                                        MatrizCaca[i][j]=palavra[contador];
                                        contador++;
                                    }
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        if(direcao==2){  //S
                        //checar se sai pela parte de baixo
                            if((strlen(palavra)+posx)>(N-1)){  //caso saia dos limites, sortear denovo
                                while((strlen(palavra)+posx)>(N-1)){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));                    
                                }
                            }
                            for(int i=posx;i<(strlen(palavra)+posx);i++){//verificar se tem alguma palavra na posicao
                                int j=posy;
                                if(MatrizCaca[i][j]!='0'){
                                    conflito=1;      // sortear denovo a posicao
                                }
                            }                    
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int i=posx;i<(strlen(palavra)+posx);i++){//verificar se tem alguma palavra na posicao
                                    int j=posy;
                                    MatrizCaca[i][j]=palavra[contador];
                                    contador++;
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        if(direcao==3){  //SO
                        //checar se sai pela di    //checar se sai pela diagonal
                            if((posy-(strlen(palavra)))<0||(strlen(palavra)+posx)>(N-1)){
                                while((posy-(strlen(palavra)))<0||(strlen(palavra)+posx)>(N-1)){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            }
                            for(int i=posx;i<(strlen(palavra)+posx);i++){ //verificar se tem alguma palavra na posicao
                                for(int j=posy;j>(posy-(strlen(palavra)));j--){
                                    if(MatrizCaca[i][j]!='0'){
                                        conflito=1;      // sortear denovo a posicao
                                    }
                                }
                            }
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int i=posx;i<(strlen(palavra)+posx);i++){
                                    for(int j=posy;j>(posy-(strlen(palavra)));j--){
                                        MatrizCaca[i][j]=palavra[contador];
                                        contador++;
                                    }
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        if(direcao==4){  //O
                            //checar se sai pela esquerda
                            if((posy-(strlen(palavra)))<0){  //caso saia dos limites, sortear denovo
                                while((posy-(strlen(palavra)))<0){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));                    
                                }
                            }    //checar se sai pela diagonal
                            if((posy-(strlen(palavra)))<0||(posx-(strlen(palavra)))<0){
                                while((posy-(strlen(palavra)))<0||(posx-(strlen(palavra)))<0){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            }
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int j=posy;j>(posy-(strlen(palavra)));j--){
                                    int i=posx;      //verificar se tem alguma palavra na posica
                                    MatrizCaca[i][j]=palavra[contador];
                                    contador++;
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        if(direcao==5){  //NO
                            //checar se sai pela diagonal
                            if((posy-(strlen(palavra)))<0||(posx-(strlen(palavra)))<0){
                                while((posy-(strlen(palavra)))<0||(posx-(strlen(palavra)))<0){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            }
                            for(int i=posx;i>(posx-(strlen(palavra)));i--){ //verificar se tem alguma palavra na posicao
                                for(int j=posy;j>(posy-(strlen(palavra)));j--){
                                    if(MatrizCaca[i][j]!='0'){
                                        conflito=1;      // sortear denovo a posicao
                                    }    if((posy+(strlen(palavra)))>(N-1)||(posx-(strlen(palavra)))<0){
                                while((posy+(strlen(palavra)))>(N-1)||(posx-(strlen(palavra)))<0){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            }
                                }
                            }
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int i=posx;i>(posx-(strlen(palavra)));i--){ //verificar se tem alguma palavra na posicao
                                    for(int j=posy;j>(posy-(strlen(palavra)));j--){
                                        MatrizCaca[i][j]=palavra[contador];
                                        contador++;
                                    }
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        if(direcao==6){  //N
                        //checar se sai por cima
                            if((posx-(strlen(palavra)))<0){
                                while((posx-(strlen(palavra)))<0){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            }
                            for(int i=posx;i>(posx-(strlen(palavra)));i--){//verificar se tem alguma palavra na posicao
                                    int j=posy;
                                    if(MatrizCaca[i][j]!='0'){
                                        conflito=1;      // sortear denovo a posicao
                                    }
                                }
                            
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int i=posx;i>(posx-(strlen(palavra)));i--){//verificar se tem alguma palavra na posicao
                                    int j=posy;
                                    MatrizCaca[i][j]=palavra[contador];
                                    contador++;
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        if(direcao==7){  //NE
                        //checar se sai    
                            if((posy+(strlen(palavra)))>(N-1)||(posx-(strlen(palavra)))<0){
                                while((posy+(strlen(palavra)))>(N-1)||(posx-(strlen(palavra)))<0){
                                    posx=rand()%(N-strlen(palavra));
                                    posy=rand()%(N-strlen(palavra));
                                }
                            } 
                            for(int i=posx;i>(posx-(strlen(palavra)));i--){ //verificar se tem alguma palavra na posicao
                                for(int j=posy;j<(posy+(strlen(palavra)));j++){
                                    if(MatrizCaca[i][j]!='0'){
                                        conflito=1; 
                                    }    
                                }
                            }
                            if(conflito==0){      //caso nao tenha nenhuma palavra na posicao
                                for(int i=posx;i>(posx-(strlen(palavra)));i--){
                                    for(int j=posy;j<(posy+(strlen(palavra)));j++){
                                        MatrizCaca[i][j]=palavra[contador];
                                        contador++;
                                    }    
                                }
                            }
                            if(conflito==1){
                                posx=rand()%(N-strlen(palavra));
                                posy=rand()%(N-strlen(palavra));
                            }
                        }
                        
                    }
                }

            }
            //preencher as lacunas
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(MatrizCaca[i][j]=='0'){
                    MatrizCaca[i][j]=rand() % 26 + 65;
                }
            }
        }
        }
    return 0;
}