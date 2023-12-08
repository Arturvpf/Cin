#include <stdio.h>
#include <string.h>

void removeABC(char *str) {
    int len = strlen(str);
    int i, j = 0;

    for (i = 0; i < len - 2; ++i) {
        if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C') {
            i += 2;
        } else {
            str[j++] = str[i];
        }
    }

    while (i < len) {
        str[j++] = str[i++];
    }

    str[j] = '\0';
}

int main() {
    char str[100];
    printf("Digite a string: ");
    scanf("%s", str);

    removeABC(str);

    printf("String modificada: %s\n", str);

    return 0;
}
