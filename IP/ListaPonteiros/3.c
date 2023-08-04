#include <stdio.h>
#include <string.h>
int main( ){
char str[50]; // String
char str_inv[50]; // String invertida
char *ptr_str = str;
char *ptr_inv = str_inv;
int i=-1;
scanf(" %s", str);
for(i=0;i<49;i++){
    *(ptr_inv+i)=*(ptr_str+(strlen(ptr_str)-i-1));
    if((i+1)==strlen(ptr_str)){ 
        *(ptr_inv + i + 1) = '\0';
        break;
    }
}
printf(" O inverso da string : %s\n\n",str_inv);
return 0;
}