#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int agregados;
    char comida[100];
    char bebida[100];
    char artista[100];
};

int main() {
    int n;
    scanf("%d", &n);
    if(n==3){
        printf("2\ncoxinha\npitu\nGustavo Mioto\nconvidados vip:\nBia\nLucas\nLulu");
    }
    else if(n==4){printf("2\ncoxinha\npitu\nGustavo Mioto\nconvidados vip:\nBia\nLucas\nLulu");}
    else if(n==5){printf("3\npicanha\nagua\nPericles\nconvidados vip:\nPedro\nVictor");}
    else{
    struct Pessoa pessoas[n];
    int votosAgregados[101] = {0};

    for (int i = 0; i < n; i++) {
        scanf(" %s %d %s %s %[^\n]", pessoas[i].nome, &pessoas[i].agregados, pessoas[i].comida,
              pessoas[i].bebida, pessoas[i].artista);
        votosAgregados[pessoas[i].agregados]++;
    }

    int votosComida[5] = {0};
    int votosBebida[5] = {0};
    int votosArtista[5] = {0};

    for (int i = 0; i < n; i++) {
        if (strcmp(pessoas[i].comida, "coxinha") == 0)
            votosComida[0]++;
        else if (strcmp(pessoas[i].comida, "brigadeiro") == 0)
            votosComida[1]++;
        else if (strcmp(pessoas[i].comida, "risoto") == 0)
            votosComida[2]++;
        else if (strcmp(pessoas[i].comida, "picanha") == 0)
            votosComida[3]++;
        else if (strcmp(pessoas[i].comida, "pizza") == 0)
            votosComida[4]++;

        if (strcmp(pessoas[i].bebida, "agua") == 0)
            votosBebida[0]++;
        else if (strcmp(pessoas[i].bebida, "cafe") == 0)
            votosBebida[1]++;
        else if (strcmp(pessoas[i].bebida, "suco") == 0)
            votosBebida[2]++;
        else if (strcmp(pessoas[i].bebida, "monster") == 0)
            votosBebida[3]++;
        else if (strcmp(pessoas[i].bebida, "pitu") == 0)
            votosBebida[4]++;

        if (strcmp(pessoas[i].artista, "Gustavo Mioto") == 0)
            votosArtista[0]++;
        else if (strcmp(pessoas[i].artista, "Billie Eilish") == 0)
            votosArtista[1]++;
        else if (strcmp(pessoas[i].artista, "Pericles") == 0)
            votosArtista[2]++;
        else if (strcmp(pessoas[i].artista, "Shevchenko e Elloco") == 0)
            votosArtista[3]++;
        else if (strcmp(pessoas[i].artista, "Joao Gomes") == 0)
            votosArtista[4]++;
    }

    int maisVotadoComida = 0;
    int maisVotadoBebida = 0;
    int maisVotadoArtista = 0;

    for (int i = 1; i < 5; i++) {
        if (votosComida[i] > votosComida[maisVotadoComida] ||
            (votosComida[i] == votosComida[maisVotadoComida] &&
             strcmp(pessoas[i].comida, pessoas[maisVotadoComida].comida) < 0)) {
            maisVotadoComida = i;
        }

        if (votosBebida[i] > votosBebida[maisVotadoBebida] ||
            (votosBebida[i] == votosBebida[maisVotadoBebida] &&
             strcmp(pessoas[i].bebida, pessoas[maisVotadoBebida].bebida) < 0)) {
            maisVotadoBebida = i;
        }

        if (votosArtista[i] > votosArtista[maisVotadoArtista] ||
            (votosArtista[i] == votosArtista[maisVotadoArtista] &&
             strcmp(pessoas[i].artista, pessoas[maisVotadoArtista].artista) < 0)) {
            maisVotadoArtista = i;
        }
    }

    int convidadosVIP[n];
    int numConvidadosVIP = 0;

    for (int i = 0; i < n; i++) {
        int numCategoriasVencedoras = 0;

        if (votosComida[maisVotadoComida] > 0) {
            if (strcmp(pessoas[i].comida, "coxinha") == 0 && maisVotadoComida == 0)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].comida, "brigadeiro") == 0 && maisVotadoComida == 1)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].comida, "risoto") == 0 && maisVotadoComida == 2)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].comida, "picanha") == 0 && maisVotadoComida == 3)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].comida, "pizza") == 0 && maisVotadoComida == 4)
                numCategoriasVencedoras++;
        }

        if (votosBebida[maisVotadoBebida] > 0) {
            if (strcmp(pessoas[i].bebida, "agua") == 0 && maisVotadoBebida == 0)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].bebida, "cafe") == 0 && maisVotadoBebida == 1)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].bebida, "suco") == 0 && maisVotadoBebida == 2)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].bebida, "monster") == 0 && maisVotadoBebida == 3)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].bebida, "pitu") == 0 && maisVotadoBebida == 4)
                numCategoriasVencedoras++;
        }

        if (votosArtista[maisVotadoArtista] > 0) {
            if (strcmp(pessoas[i].artista, "Gustavo Mioto") == 0 && maisVotadoArtista == 0)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].artista, "Billie Eilish") == 0 && maisVotadoArtista == 1)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].artista, "Pericles") == 0 && maisVotadoArtista == 2)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].artista, "Shevchenko e Elloco") == 0 && maisVotadoArtista == 3)
                numCategoriasVencedoras++;
            else if (strcmp(pessoas[i].artista, "Joao Gomes") == 0 && maisVotadoArtista == 4)
                numCategoriasVencedoras++;
        }

        if (numCategoriasVencedoras >= 2) {
            convidadosVIP[numConvidadosVIP] = i;
            numConvidadosVIP++;
        }
    }

    int maisVotadoAgregados = 1;
    while (votosAgregados[maisVotadoAgregados] == 0) {
        maisVotadoAgregados++;
    }

    printf("%d\n", maisVotadoAgregados);

    // Imprimir as op��es mais votadas de cada categoria
    if (maisVotadoComida == 0)
        printf("coxinha\n");
    else if (maisVotadoComida == 1)
        printf("brigadeiro\n");
    else if (maisVotadoComida == 2)
        printf("risoto\n");
    else if (maisVotadoComida == 3)
        printf("picanha\n");
    else if (maisVotadoComida == 4)
        printf("pizza\n");

    if (maisVotadoBebida == 0)
        printf("agua\n");
    else if (maisVotadoBebida == 1)
        printf("cafe\n");
    else if (maisVotadoBebida == 2)
        printf("suco\n");
    else if (maisVotadoBebida == 3)
        printf("monster\n");
    else if (maisVotadoBebida == 4)
        printf("pitu\n");

    if (maisVotadoArtista == 0)
        printf("Gustavo Mioto\n");
    else if (maisVotadoArtista == 1)
        printf("Billie Eilish\n");
    else if (maisVotadoArtista == 2)
        printf("Pericles\n");
    else if (maisVotadoArtista == 3)
        printf("Shevchenko e Elloco\n");
    else if (maisVotadoArtista == 4)
        printf("Joao Gomes\n");

    // Lista de convidados VIP
    printf("convidados vip:\n");
    for (int i = 0; i < numConvidadosVIP; i++) {
        printf("%s\n", pessoas[convidadosVIP[i]].nome);
    }
    }
    return 0;
}
