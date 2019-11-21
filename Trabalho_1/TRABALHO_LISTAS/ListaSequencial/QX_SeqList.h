//THIAGO MARINHO BESERRA
//MATRICULA == 420675

#ifndef QXSEQLIST_H
#define QXSEQLIST_H
#include <iostream>

class QX_SeqList {

    private:
        int *v = NULL;              //DECLARAÇÃO DO VETOR
        int size_v = 0;               //DECLARAÇÃO DO TAMANHO DO VETOR
        int MAXSIZE = 0;            //DECLARAÇÃO DO TAMANHO MAXIMO DO VETOR
    public:
       
        QX_SeqList(int n);          // Construtor recebe como parametro a capacidade total da lista 
        ~QX_SeqList();              // Destrutor libera a memoria alocada para a lista
        int size();                 // sIZE retorna o tamanho da lista
        bool isEmpty();             // isEmpty retorna true se a lista estiver vazia e false se estiver cheia
        int search(int x);          // search retorna o indice do nó caso o x esteja presente
        int at(int k);              // at retorna o k-ésimo elemento da lista
        void push_back(int x);      // push_back adiciona chave x ao final da lista
        void clear();               // clear deixa a lista vazia
        void print();               // print imprime elementos
        void printReverse();        // printReverse imprime os elementos da lista na ordem inversa
        void remove(int x);         // remove remove o primeiro elemento x da lista da lista
        void removeAll(int x);      // remove todos os elementos x da lista
        int pop_back();             // remove o ultimo elemento da lista

};

#endif
