#include <stdio.h>
#include <string.h>

int main(){
    char N[20];
    int Matriz[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
        Matriz[i][j]=0;
        }
    }

    for(int i=0;i<20;i++){
        scanf("%c ",&N[i]);
    }

    int x=0;//jinha
    int y=0;
    int posx=0;
    int posy=0;
    

    for(int i=0;i<20;i++){
        if(N[i] == 'c'){
            y--;
        }
        if(N[i] == 'b'){
            y++;
        }
        if(N[i] == 'e'){
             x--;
        }
        if(N[i] == 'd'){ 
            x++;
        }
        Matriz[y][x]++;
    }
    
    int ma=Matriz[0][0];
        for( int i = 0; i < 4; i++) {
            for( int j = 0; j < 4; j++) {
                if (Matriz[i][j] > ma) {
                    ma = Matriz[i][j];
                    posx = i;
                    posy = j;
                }
                
            }
        }
    printf("Coordenada X:%d, Y:%d",posy,posx);


}