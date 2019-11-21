// THIAGO MARINHO BESERRA
// MATRICULA = 420675

#ifndef QX_LIST_H
#define QX_LIST_H
#include <iostream>

    //criando a estrutura do nó
    struct Node{
        Node* next;
        Node* previous;
        int key;
    };
        

//criando a classe
class QX_List{
    private:

        Node* head;

    public:
    
        QX_List();                  // construtor       ok
        ~QX_List();                 // destrutor        ok
        void push_back(int);        // inserir uma key no fim da lista   ok
        int pop_back();             // remover do fim da lista e retornar o valor       ok
        void insertAfter(int, int); // inserir uma key após o k-ésimo nó da lista       ok
        void remove(int);           // remove a primeira ocorrência de key      ok
        void removeAll(int);        // remove todas as ocorrências de key        ok
        void removeNode(Node*);     // remove o nó apontado pelo ponteiro
        int removeNodeAt(int);      // remove o k-ésimo nó da lista e retorna o valor       ok
        void print();               // imprimir     ok
        void printReverse();        // imprimir reverse     ok
        bool isEmpty();             // lista vazia??    ok
        int size();                 // retorna o tamanho        ok
        void clear();               // limpa a lista        ok
        void concat(QX_List*);      // concatena a lista principal com a lista passada      ok
        QX_List* copy();            // retorna um ponteiro para cópia da lista      ok
        void copyArray(int*,int);   // Copia os elementos do array arr para a lista mantendo os anteriores  ok
        bool equal(QX_List*);       // veerifica se a lista principal é igual a lista passada       ok
        QX_List* separate(int);     // Recebe como parâmetro um valor inteiro n e divide a lista em duas
        void merge_lists(QX_List*); // Intercala lista



        };
#endif        