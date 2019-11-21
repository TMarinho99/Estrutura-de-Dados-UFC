// THIAGO MARINHO BESERRA
// MATRICULA: 420675

#ifndef ORDENACAOVETOR_H
#define ORDENACAOVETOR_H
#include <iostream>

class ordenacaoVetor {

private:
    int *v = NULL;
    int size_v = 0;
    int MAXSIZE = 0;
public:

    ordenacaoVetor(int n);                      // constrtutor do vetor
    ~ordenacaoVetor();                          // destrutor do vetor
    void inserir(int chave);                    // inserindo
    void imprimir();                            // imprimir vetor
    int getSize_v();                            // retorno o tamanho atual da lista
    void bubblesortInterativo();                // função bubblesort interativo
    void bubblesortRecursivo(int size_v);       // função bubblesort recursivo
    void insertionsortInterativo();             // função insertionsort interativa
    void insertionsortRecursivo(int size_v);    // função insertionsort recursiva
    void selectionsorttInterativo();            // função insertionsort interativa
    void selectionsorttRecursivo(int size_v, int index);// função insertionsort recursiva
    void mergesort(int p, int r);               // função mergesort
    void heapsortInterativo(int size_v);
    void heapsortRecursivo();
    void quicksort(int p, int r);


};

#endif