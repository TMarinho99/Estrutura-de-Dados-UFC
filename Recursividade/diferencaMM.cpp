#include <iostream>
using namespace std;

int diferencaMM(int *A,int n, int maior, int menor){

        if(n<0)
            return maior-menor;
        if(maior<A[n]){
            maior = A[n];
            return diferencaMM(A,n-1,maior,menor);
        }
        if(menor > A[n]){
            menor = A[n];
            return diferencaMM(A,n-1,maior,menor);
        }else
            return diferencaMM(A,n-1,maior,menor);
        
}
int main(){
    int n;
    cin >> n;
    int *A = new int[n];

    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int maior = A[0];
    int menor = A[0];
cout << "diferenca " << diferencaMM(A,n,maior,menor) << endl;


}