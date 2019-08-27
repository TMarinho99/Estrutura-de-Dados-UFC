#include <iostream>
using namespace std;

int soma_digitos(int num){
    int soma=0;
    if(num>0)
        return soma = num%10 + soma_digitos(num/10);
}

int main(){
    int num;
    cin >> num;
    if(num<0)
        num *= -1;

    cout << soma_digitos(num) << endl;
}