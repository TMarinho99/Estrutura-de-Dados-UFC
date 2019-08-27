#include <iostream>
using namespace std;

void MAX(int n, int **A){
    int k,l=0,c=0;
    k = A[0][0];

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(A[i][j]>k){
                k = A[i][j];
                l=i;
                c=j;
            }
        }
    }
 cout << "Numero maior: " << k << " linha: " << l << " coluna: " << c << endl;
}

int main(){
    int n;
    cin >> n;
    int **A = new int*[n];
    for(int i=0;i<n;i++){
        A[i] = new int[n]();
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }

    MAX(n, A);

    for(int i=0;i<n;i++)
        delete[] A[i];
    delete[] A;

}