#include <stdio.h>
#include<pthread.h>


int num_threads;
int n;
pthread_t *threads;
int *ids;
int *vet;
int ig;


typedef struct parameter{
  int l,r;
}parameter;
struct parameter *parameter;


void *thread_sort(void* threadid){
  int arg=*((int *)threadid);
  mergesort(arg,parameter[*((int *)threadid)].l,parameter[*((int *)threadid)].r);
  pthread_exit(NULL);
}

void merge(int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = vet[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = vet[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      vet[k] = L[i];
      i++;
    } else {
      vet[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    vet[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    vet[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arg,int l,int r) {
  if (l < r) {
    num_threads+=2;
    threads=(pthread_t *) realloc(ids,sizeof(pthread_t)*num_threads);
    ids=(int *) realloc(ids,sizeof(int)*num_threads);
    parameter=(struct parameter*) realloc(parameter,sizeof(struct parameter)*num_threads);

    parameter[arg+1].l= l;  //logica ta errada ainda
    parameter[arg+1].r= l + (r - l) / 2;
    parameter[arg+2].l=(l + (r - l) / 2)+1;
    parameter[arg+2].r=r;  //logica ate aqui ta errada
    for(ig;ig<ig+2;ig++){
      ids[ig] = (int*) malloc(sizeof(int));
      *((int *)ids[ig]) = ig;
      pthread_create(threads[ig],NULL,thread_sort,(void *)ids[ig]);
    }
    merge(l,l + (r - l) / 2, r);
  }
}



// Driver program
int main() {
  parameter=NULL;
  printf("Insira a quantidade de números");
  scanf("%d",&n);

  vet=(int *)malloc(sizeof(int)*n);

  for(int i=0;i<n;i++){
    scanf("%d",vet[i]);
  }

  num_threads=1;

  

  printf("Sorted array: \n");
  pthread_exit(NULL);
}
