#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char **ptr_str = NULL;
    int buffer = 0;
    int i;
    char aux[50];
    int j;
    
    while(scanf(" %s", aux) != EOF){
        buffer++;

        char **temp = (char **)realloc(ptr_str, sizeof(char *) * buffer);
        if(temp == NULL){
            for( j = 0; j < buffer - 1; j++){
                free(ptr_str[j]);
            }
            free(ptr_str);
            printf("Erro de alocacao");
            exit(1);
        }
        ptr_str = temp;

        ptr_str[buffer - 1] = (char *)malloc(strlen(aux) + 1);
        if(ptr_str[buffer - 1] == NULL){
            for(j = 0; j < buffer - 1; j++){
                free(ptr_str[j]);
            }
            free(ptr_str);
            printf("Erro de alocacao");
            exit(1);
        }
        strcpy(ptr_str[buffer - 1], aux);
    }

    for(i = 0; i < buffer; i++){
        printf("string[%d]: %s\n",i+1, ptr_str[i]);
        free(ptr_str[i]);
    }
    free(ptr_str);
}
