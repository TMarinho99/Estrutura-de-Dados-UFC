#include <iostream>
using namespace std;

int coeficiente(int n, int k){
    if(n==k || k==0)
        return 1;
    if(k==1)
        return n;
    return coeficiente(n-1,k) + coeficiente(n-1,k-1);          

}

int main(){
    int n,k;
    cin >> n;
    cin >> k;

   cout << coeficiente(n,k) << endl;
}