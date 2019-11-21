// thiago marinho beserra
// matricula: 420675

#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>
#include <queue>

    struct NoArv;

    NoArv *arv_criavazia();
    NoArv *arv_cria(int chave, NoArv *esq, NoArv *dir); // cra No com os filhos
    void arv_imprime(NoArv *no);                        // imprime as chaves da arvore
    NoArv *arv_libera(NoArv *no);                       // libera todos os nos alocados
    NoArv *arv_procurar_no(NoArv *no, int chave);       // procura no com determinada chave
    int noMenor(NoArv *n1, NoArv *n2);                  // verifico a chave maior
    int getChave(NoArv *raiz);                          // função que pega a chave da raiz
    void alterarChave(NoArv *no, int chave);            // altera a chave do no
    void alterarChaveVetor(int *v,int t, int chave, int novo);// alterando a chave no vetor

#endif 