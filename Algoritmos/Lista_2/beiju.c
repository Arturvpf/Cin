#include <stdio.h>
#include <string.h>


int main() {
    char str[100001];
    char str2[100001];
    char str3[100001];
    char str4[100001];
    int flag=0;
    int flag2=0;
    int flag3=0;
    int k=0;
    int l=0;
    int aux;
    int haha=0;
    while(fgets(str, 100001, stdin) != NULL){
        for(int i=0;i<strlen(str);i++){

            if(str[i]=='['){
                flag=1;
                int j=i;
                
                while(str[j]!=']'){
                    
                    if(str[j]=='['||str[j]==']'){

                    }
                    else{
                        str2[l]=str[j];
                        l++;
                    }
                    flag2=1;
                }
                if(flag2==1)
                str2[l+1]='\0';
                
            }
            if(flag2==1){
                str4[haha]=str[i];
                haha++;
            }
            if(flag==0){
                str3[i]=str[i];
                k=i;
            }
            if (flag==1){
                str3[k]='\0';
            }
        aux=i;
        }
        str4[haha+1]='\0';
        if(k>aux)
        strcat(str2,str3);
        strcat(str2,str4);
        printf("%s\n",str2);
    }
    return 0;
}
