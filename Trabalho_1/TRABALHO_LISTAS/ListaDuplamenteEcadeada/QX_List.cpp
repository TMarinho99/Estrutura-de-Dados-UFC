// THIAGO MARINHO BESERRA
// MATRICULA = 420675

#include "QX_List.h"
#include <iostream>
#include <climits>
using namespace std;

QX_List::QX_List(){
    head=NULL;
}

bool QX_List::isEmpty(){
    return head == NULL;    // verifico se a cabeça é igual a NULL caso seja retorna true
}

void QX_List::push_back(int key){

    Node *novo = new Node;  // declarando o nó novo
    Node *aux = new Node;   // declarando o nó  aux
    novo->key = key;        // a chave do nó novo recebe a chave da função

    if(isEmpty()){          // verifico se a lista esta vazia
        head = novo;        // cabeça recebe novo
        head->next = novo;  // cabeça proximo recebe novo
        head->previous = novo;  // cabeça anterior recebe novo 
    }else{

        aux = head;         // aux recebe cabeça
        while(aux->next != head){   // enquanto aux proximo for diferente da cabeça aux recebe aux proximo
            aux = aux->next;
        }
            aux->next = novo;       // aux proximo recebe novo
            novo->previous = aux;   // novo anterior recebe aux
            novo->next = head;      // novo proximo recebe cabeça
            head->previous = novo;  // cabeca anterior recebe novo

    }
}

int QX_List::pop_back(){
    Node *aux = new Node;               // declaro o aux
    Node *aux1 = new Node;               // declaro o aux1
    int chave;                          // inteiro que vai retornar a chave

    if(isEmpty()){          // verifico se a lista ta vazia
        cout << "Lista Vazia" << endl;  
        return -1;          // retorna -1 caso esteja vazia
    }else{
        aux = head;   // aux recebe cabeça proximo
        if(aux->next == head){      // se o aux proximo for igual a cabeca removo pois terá só um nó
            chave = aux->key;
            delete aux;
            return chave;
        }
        aux1 = aux;         // aux 1 recebe aux
        aux = aux->next;    // aux recebe aux proximo
        while(aux->next != head){ // enquanto aux for diferente da cabeca
                aux1 = aux;     // aux1 recebe aux
                aux = aux->next;    // aux recebe proximo aux
        }   
        aux1->next = aux->next;         // faço a troca, aux1 prox aponta para aux proximo
        head->previous = aux->previous; // cabeça anterior aponta para aux anterior
        chave = aux->key;               // pego a chave do nó excluido
        delete aux;                     // deleto o nó aux
    }

    return chave;                       // retorno a chave removida

}

void QX_List::insertAfter(int x,int k){
    Node *aux = new Node;           // criando aux
    Node *aux1 = new Node;          // criando aux1
    Node *novo = new Node;          // criando novo nó
    novo->key = x;                  // novo nó recebe x da função
    aux = head;                     // aux recebe a cabeça
    aux1 = aux->next;               // aux1 recebe o proximo do aux
    if(k==1){                       // caso k ==q
        aux->next = novo;           // aux proximo recebe novo
        aux1->previous = novo;      // aux1 anteriorrecebe novo
        novo->next = aux1;          // novo proximo recebe aux1
        novo->previous = aux;       // novo anterior recebe aux
    }else{                          // caso k<1
        while(k>1){
            aux = aux->next;        // aux recebe proximo aux
            aux1 = aux->next;       // aux1 recebe aux proximo
            k--;                    // decremento k
        }   
        aux->next = novo;           // aux proximo recebe novo
        aux1->previous = novo;      // aux1 anteriorrecebe novo
        novo->next = aux1;          // novo proximo recebe aux1
        novo->previous = aux;       // novo anterior recebe aux

    }

}

void QX_List::remove(int key){
    Node *aux = new Node;       // criando aux
    Node *ant = new Node;       // criando ant
    Node *prx = new Node;       // criando prx
    aux = head;                 // aux recebe cabeça

    if(isEmpty()){                      // verificando se a lista esta vazia
        cout << "Lista Vazia" << endl;
        return ;
    }
    if(head == head->next){
        head = NULL;
    }else if(head->key == key){     // verificando se a cabeça corresponde a chave
        aux = head;                 // aux recebe cabeça
        prx = head->next;           // prx recebe cabeça proximo
        ant = head->previous;       // ant recebe cabeça anterior
        head = prx;                 // cabeça recebe o prx
        head->previous = ant;       // anterior da cabeça recebe o ant
        ant->next = head;           // o proximo do ant recebe cabeça
        delete aux;                 // deleto o aux
    }else{
        aux = aux->next;            // o aux recebe o proximo pois já verificou a cabeça
        while(aux != head){         // enquanto o aux for diferente da cabeça
            if(aux->key == key){    // se a chave do aux for igual a chave da funçao
                prx = aux->next;    // prx recebe aux proximo
                ant = aux->previous;// ant recebe o anterior do aux
                ant->next = prx;    // ant proximo recebe prx
                prx->previous = ant;// anterior do prx recebe o ant
                delete aux;         // deleto o aux
                return ;            // finalizo a função
            }
            aux = aux->next;        // aux recebe o proximo do aux
        }    
        
    }

}

void QX_List::removeAll(int key){
    Node *aux = new Node;       // criando aux
    Node *ant = new Node;       // criando ant
    Node *prx = new Node;       // criando prx
    aux = head;                 // aux recebe cabeça

    if(isEmpty()){                      // verificando se a lista esta vazia
        cout << "Lista Vazia" << endl;
        return ;
    }

    if(head->key == head->next->key){
        head = NULL;
    }
    if(head->key == key){
        Node *rmv = new Node;       // criando o rmv
        aux = head;                 // aux recebe cabeça
        prx = head->next;           // prx recebe cabeça proximo
        ant = head->previous;       // ant recebe cabeça anterior
        head = prx;                 // cabeça recebe o prx
        head->previous = ant;       // anterior da cabeça recebe o ant
        ant->next = head;           // o proximo do ant recebe cabeça
        rmv = aux;                  // rmv recebe aux
        aux = aux->next;            // aux recebe aux proximo
        delete rmv;                 // removo rmv
    }
        aux = aux->next;                // aux recebe aux proximo
        while(aux != head){         // enquanto aux for diferente da cabeça
            Node *rmv = new Node;   // criando o rmv
            if(aux->key == key){    // se a chave do key for iguala chave da função
                prx = aux->next;    // prx recebe proximo do aux
                ant = aux->previous;// ant recebe aux anterior
                ant->next = prx;    
                prx->previous = ant;
                rmv = aux;
                aux = aux->next;
                delete rmv;
            }else{
                aux = aux->next;

            }

        }
       
}

void QX_List::removeNode(Node *rmv){
    Node *aux = new Node;       // criando aux
    Node *ant = new Node;       // criando ant
    Node *prx = new Node;       // criando prx
    aux = head;                 // aux recebe cabeça

    if(isEmpty()){                      // verificando se a lista esta vazia
        cout << "Lista Vazia" << endl;
        return ;
    }

    if(head->key == rmv->key){      // verificando se a cabeça corresponde a chave do nó
        aux = head;                 // aux recebe cabeça
        prx = head->next;           // prx recebe cabeça proximo
        ant = head->previous;       // ant recebe cabeça anterior
        head = prx;                 // cabeça recebe o prx
        head->previous = ant;       // anterior da cabeça recebe o ant
        ant->next = head;           // o proximo do ant recebe cabeça
        delete aux;                 // deleto o aux
        return ;
    }else{
        aux = aux->next;            // o aux recebe o proximo pois já verificou a cabeça
        while(aux != head){         // enquanto o aux for diferente da cabeça
            if(aux->key == rmv->key){// se a chave do aux for igual a chave da do nó
                prx = aux->next;    // prx recebe aux proximo
                ant = aux->previous;// ant recebe o anterior do aux
                ant->next = prx;    // ant proximo recebe prx
                prx->previous = ant;// anterior do prx recebe o ant
                delete aux;         // deleto o aux
                return ;            // finalizo a função
            }
            aux = aux->next;        // aux recebe o proximo do aux
        }    
        
    }
}

int QX_List::removeNodeAt(int k){
    Node *aux = new Node;           // criando aux
    Node *ant = new Node;          // criando ant
    Node *prx = new Node;          // criando prx
    int chave;
    aux = head;

    if(head == head->next){
        chave = head->key;
        head = NULL;
    }else if(k == 1){
        aux = head;                 // aux recebe cabeça
        prx = head->next;           // prx recebe cabeça proximo
        ant = head->previous;       // ant recebe cabeça anterior
        head = prx;                 // cabeça recebe o prx
        head->previous = ant;       // anterior da cabeça recebe o ant
        ant->next = head;           // o proximo do ant recebe cabeça
        chave = aux->key;
        delete aux;                 // deleto o aux
        cout << "aqui" << endl;
        print();
    }else{
        while(k > 1){
            aux = aux->next;
            k--;
        }
        chave = aux->key;
        prx = aux->next;
        ant = aux->previous;
        prx->previous = ant;
        ant->next = prx;
        delete aux;
    }

    return chave;

}

void QX_List::print(){
    Node *aux = new Node;               // declaro o aux
    if(isEmpty()){                      // verifico se a lista esta vazia caso esteja imprimo Lista vazia
        cout << "Lista Vazia" << endl;
        return ;
    }else{
        aux = head;                     // aux recebe a cabeça
        cout << aux->key << " ";        // imprimo a cabeça
        aux = aux->next;                // aux recebe aux proximo
        while(aux != head){             // enquanto o aux for diferente da cabeça
            cout << aux->key << " ";    // imprimo a chave do nó
            aux = aux->next;            // aux recebe aux proximo
        }
        cout << endl;                   // quebra de linha
    }
}

void QX_List::printReverse(){
    Node *aux = new Node;
    if(isEmpty()){
        cout << "lizta Vazia" << endl;
    }else{
        aux = head->previous;
        cout << aux->key << " ";
        aux = aux->previous;
        while(aux != head->previous){
            cout << aux->key << " ";
            aux = aux->previous;
        }
        cout << endl;
    }
}

int QX_List::size(){
    Node *aux = new Node;
    int cont = 0;

    if(isEmpty()){
        return 0;
    }else{
        aux = head;
        cont++;
        while(aux->next != head){
            aux = aux->next;
            cont++;
        }
        return cont;
    }

}

void QX_List::clear(){
    Node *aux = new Node;

    if(isEmpty()){
        cout << "Lista Vazia" << endl;
        return ;
    }else{
        aux = head->next;
        while(aux != head){
            Node *rmv = new Node;
            rmv = aux;
            aux = aux->next;
            delete rmv;
        }
        head = NULL;

    }
    
}

void QX_List::concat(QX_List *lista){
    Node *fim1 = new Node;
    Node *fim2 = new Node;

    fim1 = head->previous;
    fim2 = lista->head->previous;

    fim1->next = lista->head;
    lista->head->previous = fim1;

    fim2->next = head;
    head->previous = fim2;
    return ;
}

QX_List* QX_List::copy(){
    QX_List *aux;
    aux = new QX_List();
    aux->head = head;
    return aux;
}

void QX_List::copyArray(int *v, int n){
    Node *aux = new Node;
    aux = head->previous;
    for(int i=0; i < n; i++){

        Node *novo = new Node;
        novo->key = v[i];
        aux->next = novo;
        novo->previous = aux;
        novo->next = head;
        head->previous = novo;
        aux = novo;

    }


}

bool QX_List::equal(QX_List *lst){
    Node *aux1 = new Node;
    Node *aux2 = new Node;
    int cont = 1;
    aux1 = head;
    aux2 = lst->head;

    if(size() == lst->size()){

        if(aux1->key == aux2->key){
            aux1 = aux1->next;
            aux2 = aux2->next;
            while(aux1 != head){
                if(aux1->key == aux2->key){
                    aux1 = aux1->next;
                    aux2 = aux2->next;
                }else{
                    return false;
                }
                
            }
            return true;

        }else{
            return false;
        }
    }else{
        return false;
    }    
    
}

QX_List* QX_List::separate(int n){
    QX_List *sprt;
    sprt = new QX_List();

    Node *aux = new Node;
    Node *aux1 = new Node;
    Node *aux2 = new Node;
    aux = head;

    if(aux->key == n){
        sprt->head = aux->next;
        head->next = head;
        head->previous = head;
        return sprt;        
    }else if(head->previous->key == n){
        sprt->head = head;
        head = NULL;
        return sprt;
    }else{
        aux = aux->next;
        while(aux != head){
            if(aux->key == n){
                aux1 = aux->next;
                aux2 = head->previous;
                aux1->previous = aux2;
                aux2->next = aux1;
                head->previous = aux;
                aux->next = head;
                sprt->head = aux1;
                return sprt;
            }
            aux = aux->next;
        }
    }
    return NULL;

}

void QX_List::merge_lists(QX_List *lst2){
    Node *aux = new Node;
    Node *aux2 = new Node;

    QX_List *nova;
    nova = new QX_List();

    aux = head;
    aux2 = lst2->head;


    nova->push_back(aux->key);
    nova->push_back(aux2->key);
    
    aux = aux->next;
    aux2 = aux2->next;



    int cont = 0;
    while(aux != head && aux2 != lst2->head){
        
        nova->push_back(aux->key);
        nova->push_back(aux2->key);

        aux = aux->next;
        aux2 = aux2->next;

    }
    clear();
    lst2->clear();
    head = nova->head;

}

QX_List::~QX_List(){
    Node *aux = new Node;       // declaro o aux
    Node *rmv = new Node;       // declaro o rmv
    if(head != NULL){
        aux = head->next;           // aux recebe cabeça proximo
        while(aux != head){         // enquanto aux for diferente da cabeça
            rmv = aux;              // rmv recebe aux
            aux = aux->next;        // aux recebe aux proximo
            delete rmv;             // deleto rmv
        }
        delete aux;                 // deleto aux que é a cabeça
    }
}