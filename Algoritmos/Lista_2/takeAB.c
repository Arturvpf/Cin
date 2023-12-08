#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void takeabc();
int main(){
    takeabc();
    return 0;
}

void takeabc(){
    char str[3*10*10*10*10*10];
    int *key=NULL;
    int j=0;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='B'){

        }
        else if(str[i]=='C'){

        }
        else if(str[i]=='A'){
            j++;
            key=(int *)realloc(key,sizeof(int)*j);
            key[j-1]=i;
            if(str[i+1]=='B'){
                if(str[i+2]=='C'){
                    int k;
                    if(i+3<=strlen(str)){
                        for(k=i;k<=strlen(str)-3;k++){
                            str[k]=str[k+3];
                        }
                        j--;
                        if(j>0)
                         key=(int *)realloc(key,sizeof(int)*j);
                        else
                            key=NULL;
                        if(j>0)
                        i=key[j-1];
                        else
                        i=0;
                        if(key[j-1]>20)
                        i-=3;
                        else i=0;


                        
                        
                    }
                    else{
                        str[i]='\0';

                    }
                }
            }
        }
    }
    if(strcmp(str,"ABC")==0){
        str[0]='\0';
    }
    printf("%s",str);
    free(key);
}