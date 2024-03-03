#include <stdio.h>
#include <string.h>

void removeABC(char *str) {
    char *s;
    int tam= strlen(str);
    
    while ((s = strstr(str, "ABC")) != NULL) {
        memmove(s,s+3,tam-(s-str)-2);
        tam-= 3;
    }
}

int main() {
    char str[3*10*10*10*10*10];
    scanf("%s",str);

    removeABC(str);

    printf("%s",str);

    return 0;
}
