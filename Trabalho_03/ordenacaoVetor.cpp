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
    int j = size_v-2;

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

        swap(v[min],v[i]);    
        
    }
    
}

int minIndex(int *v,int i, int j){
    if(i==j)
        return i;

    int k = minIndex(v,i+1, j);

    return (v[i] < v[k])? i : k;    

}

void ordenacaoVetor::selectionsorttRecursivo(int size_v, int index){

    if(index == size_v)
        return;

    int k = minIndex(v,index,size_v-1);

    if(k!=index)
        swap(v[k],v[index]);

    selectionsorttRecursivo(size_v, index+1);

}

void merge (int A[], int p, int q, int r) {
 int i, j, k;
 int *W = new int[r-p+1]; // Vetor auxiliar
 i = p; j = q+1; k = 0;
 // Intercala A[p..q] e A[q+1..r]
    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            W[k++] = A[i++];
        else
            W[k++] = A[j++];
    }
    while (i <= q) W[k++] = A[i++];
    while (j <= r) W[k++] = A[j++];
    // Copia vetor ordenado W para o vetor A
    for (i = p; i <= r; i++)
        A[i] = W[i-p];
    delete[] W;
}

void ordenacaoVetor::mergesort(int p, int r){
    if (p < r) {
        int q = (p + r) / 2; // Dividir
        // Conquistar
        mergesort(p, q);
        mergesort(q + 1, r);
        // Combinar
        merge(v, p, q, r);
 }
}

void ordenacaoVetor::heapsortInterativo(int size_v){
    
   int i = size_v / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          size_v--;
          if (size_v <= 0) return;
          t = v[size_v];
          v[size_v] = v[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < size_v) {
          if ((filho + 1 < size_v)  &&  (v[filho + 1] > v[filho]))
              filho++;
          if (v[filho] > t) {
             v[pai] = v[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      v[pai] = t;
   }
}

void heapify(int arr[], int n, int i) { 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

void ordenacaoVetor::heapsortRecursivo(){
    for (int i = size_v / 2 - 1; i >= 0; i--) 
        heapify(v, size_v, i);

    for (int i = size_v - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(v[0], v[i]); 
  
        // call max heapify on the reduced heap 
        heapify(v, i, 0); 
    } 
}

int separa (int v[], int p, int r) {
    int c = v[r];
    int j = p;
        for (int k = p; k < r; k++) {
            if (v[k] <= c) {
                swap(v[k], v[j]);
                j++;
            }
        }
        v[r] = v[j];
        v[j] = c;
        return j;
}

void ordenacaoVetor::quicksort(int p, int r){
    if (p < r) {
        int i = separa(v, p, r);
        quicksort(p, i-1);
        quicksort(i+1, r);
     }
}

ordenacaoVetor::~ordenacaoVetor(){
    
}