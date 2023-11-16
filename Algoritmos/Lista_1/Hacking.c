#include<stdio.h>
#include<stdlib.h>
void MergeSort();
void merge();
int Comparar();

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    int Vet[n];
    for(int i=0;i<n;i++){
        scanf("%d",&Vet[i]);
    }
    MergeSort(Vet,0,n-1);

    int d=Comparar(Vet,n,k);
    printf("%d\n",d);

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
int Comparar(int *A,int n, int k){
    int d=0;
    int temp;
    for(int i=0;i<n-1;i++){
        if((A[i+1]-A[i])==k){
            d++;
        }
        else if(A[i+1]-A[i]<k){
            int j=i+1;
            while(j<n ){
                if((A[j]-A[i])==k){
                    d++;
                    break;
                }
                j++;
            }
        }
        else{
            temp=A[i+1];
            A[i+1]=A[i];
            A[i]=temp;
        }
    }
    return d;
}