#include <iostream>
using namespace std;

void inverter(int *A, int e, int d){
    if(e<d){
        int aux = A[e];
        A[e]=A[d];
        A[d]=aux;
        inverter(A,e+1,d-1);
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    inverter(A,0,n-1);
    for(int i=0;i<n;i++){
        cout << A[i] << endl;
    }
}