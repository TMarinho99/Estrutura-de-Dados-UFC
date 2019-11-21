// thiago marinho beserra
// matricula: 420675

#include "Arvore.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// estrutura 
struct NoArv
{
    int chave;
    struct NoArv *esq;
    struct NoArv *dir;
}; // Tipo no da Arvore

// função que retorna o null para criar vazia
NoArv* arv_criavazia(){
    return NULL;
}
// função que cria a um elemento da arvore, o NoArv novo recebe a chave
// e o no esq e dir e retorna o novo
NoArv* arv_cria(int chave, NoArv* esq, NoArv* dir){
    NoArv* novo = new NoArv;
    novo->chave = chave;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

// alterar a chave de um nó
void alterarChave(NoArv *no,int chave){
    no->chave = chave;
}

// imprimo a arvore recursivamente e in-ordem
void arv_imprime(NoArv* no){
    if(!arv_vazia(no)){
        cout << no->chave << endl;
        arv_imprime(no->esq);
        arv_imprime(no->dir);
    }
}


// função que libera recursivamente uma arvore 
NoArv* arv_libera(NoArv* no){
    if(no != NULL){
        no->esq = arv_libera(no->esq);
        no->dir = arv_libera(no->dir);
        cout << "Liberando... " << no->chave << endl;
        delete no;
    }
    return NULL;
}

// procurar o nó em que a chave é igual e se ele é a folha
NoArv* arv_procurar_no(NoArv* no, int chave){
    // procura o nó com chave igual e se ele é uma folha
    if(no == NULL || (no->chave == chave && no->esq == NULL && no->dir == NULL) )
        return no;
    NoArv* esq = arv_procurar_no(no->esq, chave);
    if(esq != NULL)
        return esq;
    else
        return arv_procurar_no(no->dir,chave);  

}

// altera a chave no vetor 
void alterarChaveVetor(int *v,int t,int chave,int novo){
    for(int i=0;i<t;i++){
        if(v[i]==chave)
            v[i] = novo;
    }
}

// retorna o valor do menor nó
int noMenor(NoArv *n1, NoArv *n2){
    if(n1->chave <= n2->chave)
        return n1->chave;
    else
        return n2->chave;
}

//retorna a chave de um nó
int getChave(NoArv *no){
    return no->chave;
}