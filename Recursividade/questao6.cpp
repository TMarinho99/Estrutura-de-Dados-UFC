#include <iostream>
using namespace std;

void imprimir(int n, int k){
    if(n>0 && k>0)
        cout << imprimir(n-1,k);
    else
        return;
    
}

int main(){
    int n,k;
    cin >> n;
    cin >> k;

    imprimir(n,k);

}