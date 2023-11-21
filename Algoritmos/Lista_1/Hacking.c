#include<stdio.h>
#include<stdlib.h>
void MergeSort();
void merge();
int soma();
int BS();

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    int Vet[n];
    for(int i=0;i<n;i++){
        scanf("%d",&Vet[i]);
    }
    MergeSort(Vet,0,n-1);

    
    printf("%d\n",soma(Vet,n,k));

}
void MergeSort(int *A,int l, int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        merge(A,l,r);
    }
}
void merge(int *A, int l, int r){
    int temp[r+1];
    int m;
    int i1,i2;
    int curr;
    for(int i=l;i<=r;i++){
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
            else if(temp[i1]<=temp[i2]){
                A[curr]=temp[i1++];
            }
            else{
                A[curr]=temp[i2++];
            }
        }
            
}
int soma(int *A,int n, int k){
    int s;
    int d=0;
    for(int i=0;i<n;i++){
        s=A[i]+k;
        if(BS(A,n,s)==1){
            d++;
        }
    }
    return d;
    
}

int BS(int *A,int n,int k){
   int l=0;
   int r=n-1;
   int m;
   while(l<=r){
    m=(l+r)/2;
    if(k==A[m]){
        return 1;
    }
    else if(k<A[m]){
        r=m-1;
    }
    else l=m+1;
   }
   return -1;
}