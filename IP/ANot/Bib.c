//parte de Anot08_15
void salvaVetor(FILE *arq, float *vet, int tam) {
    //FILE *arq;
    //if((arq=fopen("test.bin","w"))!=NULL) {
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(vet, sizeof(float), tam, arq);
    //    fclose(arq);
    //}
}
float *carregaVetor(FILE *arq, int *tam) {
    //FILE *arq;
    float *uai = NULL;
    //if((arq=fopen("test.bin","r"))!=NULL) {
        fread(tam, sizeof(int), 1, arq);
        uai = (float *) malloc(sizeof(float) * (*tam));
        if(uai==NULL) { printf("Uai, me lasquei\n"); exit(1); }
        fread(uai, sizeof(float), *tam, arq);
    //    fclose(arq);
    //}
    return uai;
}
float *inserirVetor(float *dVet, int *tamDV, float *vet, int tamV) {
    float *vTmp = dVet;
    int i;
    dVet = (float *) realloc(dVet, sizeof(float) * ((*tamDV)+tamV));
    if(dVet==NULL) { free(vTmp); exit(1); }
    for(i=0; i<tamV; i++)
        dVet[(*tamDV)+i] = vet[i];
    *tamDV += tamV;
    return dVet;
}
void printVetor(float *dVet, int tam) {
    int i;
    for(i=0; i<tam; i++)
        printf("vet[%d]=%.2f\n", i+1, dVet[i]);
}
