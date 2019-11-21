//  THIAGO MARINHO BESERRA
//  MATRICULA == 420675

#include <iostream>
#include <climits>
#include "QX_SeqList.h"
using namespace std;



QX_SeqList::QX_SeqList(int n){      // Chamando o construtor da classe
    if(n>0){                        // verificando se o tamanho do n é maior que 0 para criar o vetor com um tamanho
        v = new int[n];             // criando o vetor
        size_v = 0;                 // iniciado o tamanho do vetor com 0
        MAXSIZE = n;                // tamanho maximo do vetor recebendo n
    }
    cout << "==============================================" << endl;
    cout << "||ista Criada Com Sucesso                   ||" << endl;
    cout << "==============================================" << endl;
}

QX_SeqList::~QX_SeqList(){                              // Destrutor
    if(v != NULL) {                                     // verifico se o vetor não é Nulo
        delete[] v;                                     // deleto o vetor 
        cout << "==============================================" << endl;
        cout << "||QX_SeqList Destruida                      ||" << endl;
        cout << "==============================================" << endl;         // imprimo msg 
    }
}

int QX_SeqList::size(){                 // Função para verificar tamanho do vetor
    return size_v;                  // retornando tamanho do vetor
}

bool QX_SeqList::isEmpty(){              // Verificando se a lista esta vazia
    return size_v == 0;             // retornando true se o tamanho da lita for igual a 0
}

int QX_SeqList::search(int x){             // Buscar chave e retorna o indice     

    for(int i = 0; i < size_v; i++){       // Fazendo a verificação de 0 ate size_v caso encontre retorno i
        if(v[i] == x)
            return i;
    }

    return INT_MIN;                         // Caso não tenha encontrado retorno INT_MIN
}

int QX_SeqList::at(int k){                     // devolve o k-ésimo elemento da lista

    for(int i = 0; i < size_v; i++){           // Fazendo verificação de 0 ate size_v caso encontre retorno o nó
        if(i == k)
            return v[i];
    }

    return INT_MIN;                             // caso não encntre retorno INT_MINf
}

void QX_SeqList::push_back(int x){  // Adiciona chave x ao final da lista
    if(size_v == MAXSIZE){           // Primeiro verifico se a lista está cheia, caso esteja imprimo uma mensagem de erro
        cout << "==============================================" << endl;
        cout << "||       >>>>>   Lista Cheia  <<<<<         ||" << endl;
        cout << "==============================================" << endl;
        return ;
    }    
    v[size_v] = x;                  // adiciono o elemento ao vetor na posição do size_v
    size_v++;                       // Logo depois incremento o size_v
    cout << "==============================================" << endl;
    cout << "||Elemento Adicionado                       ||" << endl;
    cout << "==============================================" << endl;
}

void QX_SeqList::clear(){
    size_v = 0;                     // lIMPO A LISTA ZERANDO o tamanho dela        
}

void QX_SeqList::print(){
    if(isEmpty()){
        cout << "==============================================" << endl;
        cout << "||       >>>>>   Lista Vazia  <<<<<         ||" << endl;
        cout << "==============================================" << endl;
        return ;
    }
    cout << "======" << endl;
    for(int i=0; i< size_v; i++){           // Percorro o veotr e imprimo todos os elementos
        cout << "||" << v[i] << "||" << endl;
    }
    cout << "======" << endl;
}

void QX_SeqList::printReverse(){
    if(isEmpty()){
        cout << "==============================================" << endl;
        cout << "||       >>>>>   Lista Vazia  <<<<<         ||" << endl;
        cout << "==============================================" << endl;
        return ;
    }
    cout << "======" << endl;
    for(int i = size_v-1; i >= 0;i--){          // Percorro o vetor do fim para o inicio e vou imprimindo
        cout << "||" << v[i] << "||" << endl;
    }
    cout << "======" << endl;
}

void QX_SeqList::remove(int x){                // Remove elemento o primeiro x da lista
    int index = search(x);                     // Procuro o indice do inteiro
    if(index != -1) {                          // Verifico se ele existe dentro do vetor vendo se é diferente de -1
        while(index <= size_v-2) {             // Movo ele para a posição de tamanho do vetor menor 2
            v[index] = v[index+1];             //movendo o elemento para o final
            index++;                           // Incrementando o index ate size_v -2
        }
        size_v--;                              // Diminuindo o tamanho da lista e eliminando o vetor
    }
    cout << "==============================================" << endl;
    cout << "||Elemento Removido                         ||" << endl;
    cout << "==============================================" << endl;
}

void QX_SeqList::removeAll(int x){
    int index = search(x);
    while(index != INT_MIN){                            // Enquanto index existir Faço a operação
        if(index != INT_MIN) {                          // Verifico se ele existe dentro do vetor vendo se é diferente de -1
            while(index <= size_v-2) {             // Movo ele para a posição de tamanho do vetor menor 2
                v[index] = v[index+1];             //movendo o elemento para o final
                index++;                           // Incrementando o index ate size_v -2
            }
            size_v--;                              // Diminuindo o tamanho da lista e eliminando o vetor
        }
        index = search(x);                         // Procuro o indice do inteiro
    }
    cout << "==============================================" << endl;
    cout << "||Elementos Removidos                       ||" << endl;
    cout << "==============================================" << endl;
}

int QX_SeqList::pop_back(){         //remove o ultimo elemento da lista
    cout << "==============================================" << endl;
    cout << "||Elemento Removido                         ||" << endl;
    cout << "==============================================" << endl;
    return size_v--;                //reduzo o tamanho da lista eliminando o ultimo elemento

}   