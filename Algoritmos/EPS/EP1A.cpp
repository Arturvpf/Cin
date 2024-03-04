#include<stdio.h>
#include<string.h>

typedef struct {
    char n[31];
    int t;
}Participante;

void Mergesort(Participante *A,int c);
void Merge();

int main(){
    int c;
    scanf("%d",&c);
    Participante P[c];
    for(int i=0;i<c;i++){
        int t;
        scanf(" %s %d",P[i].n,&P[i].t);
    }
    Mergesort(P,c);
    for(int i=0;i<c;i++){
        printf("%s %d\n",P[i].n,P[i].t);
    }
}
void merge(Participante *A, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Participante L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].t <= R[j].t) {
            A[k] = L[i];
            
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Participante *A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        merge(A, left, mid, right);
    }
}
