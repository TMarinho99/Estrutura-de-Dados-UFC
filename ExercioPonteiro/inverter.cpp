#include <iostream>
using namespace std;

void inverter(int A[], int n){
    for(int i=n-1;i>=0;i--){
        cout << A[i] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    inverter(A, n);

}