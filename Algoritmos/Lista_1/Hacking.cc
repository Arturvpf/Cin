#include<iostream>
#include<vector>

using namespace std;

void MergeSort(vector<int>& A, int l, int r);
void merge(vector<int>& A, int l, int r);
int soma(const vector<int>& A, int k);
int BS(const vector<int>& A, int k);

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> Vet(n);
    for(int i=0;i<n;i++){
        cin >> Vet[i];
    }
    MergeSort(Vet,0,n-1);

    cout << soma(Vet, k) << endl;
}

void MergeSort(vector<int>& A, int l, int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        merge(A,l,r);
    }
}

void merge(vector<int>& A, int l, int r){
    vector<int> temp(r+1);
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

int soma(const vector<int>& A, int k){
    int s;
    int d=0;
    for(int i=0;i<A.size();i++){
        s=A[i]+k;
        if(BS(A,s)==1){
            d++;
        }
    }
    return d;
}

int BS(const vector<int>& A, int k){
   int l=0;
   int r=A.size()-1;
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