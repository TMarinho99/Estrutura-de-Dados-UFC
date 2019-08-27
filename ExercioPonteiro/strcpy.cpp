#include <iostream>
using namespace std;

char *strcpy(char *destino, char *origem){
        for(int i = sizeof(origem);i>=0;i--){
            destino[i]=origem[i];
        }
        return destino;
}

int main(){
    char *origem = new char[50];
    char *destino = new char[50];

    cin.getline(origem, 50);

    cout << strcpy(destino,origem);




}