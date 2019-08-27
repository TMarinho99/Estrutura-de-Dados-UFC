#include <iostream>
using namespace std;

int triangulo(int *A,int n){
    for(int i=0;i<n;i++){
            cout << " " << A[i];
        }
        cout << endl;
    int aux[n-1];
    
    if(n>0){
        for(int i=0;i<n-1;i++){
            aux[i] = A[i] + A[i+1];
        }
        triangulo(aux, n-1);
    }    
    
}

int main(){
    int n;
    cin >> n;
    int *A = new int[n];

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

   triangulo(A,n);
}