#include<stdio.h>
#include<stdlib.h>

void MergeSort(long long int *A,long long int l, long long int r);
void merge(long long int *A, long long int l, long long int r);
void printar();

int main(){
    long long int n;
    scanf("%lld",&n);

    long long int Vet[n];
    
    for(long long int i=0;i<n;i++){
        scanf("%lld",&Vet[i]);
    }
    MergeSort(Vet,0,n-1);

    long long int cupom;

    scanf("%lld",&cupom);

    long long int VetC[cupom];
    for(long long int i=0;i<cupom;i++){
        scanf("%lld",&VetC[i]);
    }
    printar(VetC,Vet,cupom,n);
}

void MergeSort(long long int *A,long long int l, long long int r){
    if(l<r){
        long long int m=(l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        merge(A,l,r);
    }
}
void merge(long long int *A, long long int l, long long int r){
    long long int temp[r+1];
    long long int m;
    long long int i1,i2;
    long long int curr;
    for(long long int i=l;i<=r;i++){
        temp[i]=A[i];
    }
        m=(l+r)/2;
        i1=l;i2=m+1;
    
        for(curr=l;curr<=r;curr++){
            if(i1==(m+1)){
                A[curr]=temp[i2++];
            }
            else if(i2>r){
                A[curr]=temp[i1++];
            }
            else if(temp[i1]>=temp[i2]){
                A[curr]=temp[i1++];
            }
            else{
                A[curr]=temp[i2++];
            }
        }
            
}
void printar(long long int *VetC,long long int *Vet,long long int cupom, long long int n){
    long long int soma=0;
    long long int i=0;

        for(long long int j=0;j<n;j++){
                soma+=Vet[j]; 
        }
        for(long long int j=0;j<cupom;j++){
            printf("%lld\n",soma-Vet[VetC[j]-1]);//.
        }
}