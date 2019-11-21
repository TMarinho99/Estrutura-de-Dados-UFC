#include "ordenacaoVetor.h"
#include <iostream>
using namespace std;

ordenacaoVetor::ordenacaoVetor(int n){
    if (n > 0){                   // verificando se o tamanho do n é maior que 0 para criar o vetor com um tamanho
        v = new int[n]; // criando o vetor
        size_v = 0;     // iniciado o tamanho do vetor com 0
        MAXSIZE = n;    // tamanho maximo do vetor recebendo n
    }
}

void ordenacaoVetor::inserir(int chave){
    if (size_v < MAXSIZE){
        v[size_v] = chave;
        size_v++;
    }
}

void ordenacaoVetor::imprimir(){
    for (int i = 0; i < size_v; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int ordenacaoVetor::getSize_v(){
    return size_v;
}

void ordenacaoVetor::bubblesortInterativo(){
    for (int i = 0; i < size_v - 1; i++) {
        for (int j = size_v - 1; j > i; j--){
            if (v[j] < v[j - 1]){
                swap(v[j], v[j - 1]);
            }
        }
    }
}

void ordenacaoVetor::bubblesortRecursivo(int size_v){
    if (size_v == 1)
        return;
    for (int i = 0; i < size_v - 1; i++){
        if (v[i] > v[i + 1])
            swap(v[i], v[i + 1]);
    }

    bubblesortRecursivo(size_v - 1);
}

void ordenacaoVetor::insertionsortInterativo(){
    int i, j, key;
    for (j = 1; j < size_v; j++){
        key = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > key){
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}

void ordenacaoVetor::insertionsortRecursivo(int size_v){

    if(size_v <= 1)
        return;
    
    insertionsortRecursivo(size_v-1);

    int ultimo = v[size_v-1];
    int j = size_v-1;

    while(j >= 0 && v[j]>ultimo){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = ultimo;

}

void ordenacaoVetor::selectionsorttInterativo(){
    for (int i = 0; i < size_v-1; i++){
        int min = i;
        for(int j = i+1; j<size_v;j++)
            if(v[j]<v[min])
                min = j;

        swap(v[i],v[min]);    
        
    }
    
}

int minIndex(int *v,int i, int j){
    if(i==j)
        return i;

    int k = minIndex(v,i+1, j);

    return (v[i]<v[j])? i : k;    

}

void ordenacaoVetor::selectionsorttRecursivo(int size_v, int index){

    if(index == size_v)
        return;

    int k = minIndex(v,index,size_v-1);

    if(k!=index)
        swap(v[k],v[index]);

    selectionsorttRecursivo(size_v, index+1);

}

ordenacaoVetor::~ordenacaoVetor(){

}