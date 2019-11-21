#include "ordenacaoVetor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int n = 10;
    ordenacaoVetor vetor(n);

    srand((unsigned)time(0));

    for(int i=0; i<10;i++){
        vetor.inserir(rand()%100);
    }
    cout << "vetor" << endl;
    vetor.imprimir();
    vetor.quicksort(0,9);
    cout << "vetor" << endl;
    vetor.imprimir();



}