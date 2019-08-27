#include <iostream>
using namespace std;

int soma_positivos(int *A, int n){
    int soma=0;

    if(n>=0 && A[n]>0)
        return soma = A[n] + soma_positivos(A,n-1);
    else if(A[n]<0)
        return soma_positivos(A,n-1);
    else
        return soma;
        
    
}


int main(){
    int n;
        cin >> n;
        int *A = new int[n];

        for(int i=0;i<n;i++){
            cin >> A[i];
        }

  cout <<  soma_positivos(A, n-1);
}