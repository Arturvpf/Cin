#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define NUM_THREADS 2
#define LINHAS 3
#define COLUNAS 3
int A[3][3] = { {1, 2,5}, {3, 4,2}, {5, 6,1} };
int B[3][3] = {{1, 2,5}, {3, 4,2}, {5, 6,1} };
int R[3][3];
void *threadCode(void *tid){
int i,j, k;
int threadId = (*(int *)tid);
for(i=threadId; i < LINHAS; i = i+NUM_THREADS) {
for (j=0;j<COLUNAS;j++) {
R[i][j] = 0;
for(k=0;k< COLUNAS;k++) {
R[i][j] = A[i][j] + B[i][k];
int * matriz2[k][j];
}
}
}
}
int main (int argc, char *argv[]){
pthread_t threads[NUM_THREADS];
int *taskids[NUM_THREADS];
int i,j;
for(i=0; i<NUM_THREADS; i++){
taskids[i] = (int *)
malloc(sizeof(int));
*taskids[i] = i;
pthread_create(&threads[i],
NULL,threadCode,
(void *)taskids[i]);
}
for(i=0; i<NUM_THREADS;i++) {
pthread_join(threads[i], NULL);
}
for(i=0; i < LINHAS; i++) {
for (j=0;j<COLUNAS;j++) {
printf("%d\t", R[i][j]);
}
printf("\n");
}
}