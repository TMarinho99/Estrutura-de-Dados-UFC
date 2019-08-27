#include <iostream>
using namespace std;

void mm(int A[], int n, int *min, int *max){
    *min = A[0];
    *max = A[0];
    for(int i=1; i < n; i++){
        if(A[i] < *min){
            *min = A[i];
        }if(A[i] > *max){
            *max = A[i];
        }
    }
    cout << *min << *max;

}    

int main(){
    int n, min, max;
    cin >> n;
    int A[n];

    
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    mm( A, n, &min, &max);
}