#include<iostream>
#include<vector>

using namespace std;

void MergeSort(vector<long long>& A, long long l, long long r);
void merge(vector<long long>& A, long long l, long long r);
void printar(const vector<long long>& VetC, const vector<long long>& Vet);

int main(){
    long long n;
    cin >> n;

    vector<long long> Vet(n);
    
    for(long long i=0;i<n;i++){
        cin >> Vet[i];
    }
    MergeSort(Vet,0,n-1);

    long long cupom;

    cin >> cupom;

    vector<long long> VetC(cupom);
    for(long long i=0;i<cupom;i++){
        cin >> VetC[i];
    }
    printar(VetC,Vet);
}

void MergeSort(vector<long long>& A, long long l, long long r){
    if(l<r){
        long long m=(l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        merge(A,l,r);
    }
}
void merge(vector<long long>& A, long long l, long long r){
    vector<long long> temp(r+1);
    long long m;
    long long i1,i2;
    long long curr;
    for(long long i=l;i<=r;i++){
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
void printar(const vector<long long>& VetC, const vector<long long>& Vet){
    long long soma=0;
    long long i=0;

        for(long long j=0;j<Vet.size();j++){
                soma+=Vet[j]; 
        }
        for(long long j=0;j<VetC.size();j++){
            cout << soma-Vet[VetC[j]-1] << endl;
        }
}