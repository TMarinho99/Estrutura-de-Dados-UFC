// THIAGO MARINHO BESERRA
// MATRICULA: 420675


#include <iostream>
#include <climits>
#include "QX_List.h"
using namespace std;

int menu(){
int resp;
    cout << "==============================================" << endl;
    cout << "|| 1-Inserir Elemento                       ||" << endl;
    cout << "|| 2-Remover do Fim da Lista                ||" << endl;
    cout << "|| 3-Inserir após o N-ésimo termo           ||" << endl;
    cout << "|| 4-Remover Primeiro Elemento 'x' da Lista ||" << endl;
    cout << "|| 5-Remover Todos os Elementos 'x' da Lista||" << endl;
    cout << "|| 6-Remover nó por um Ponteiro             ||" << endl;
    cout << "|| 7-Remover o N-ésimo nó da Lista          ||" << endl;
    cout << "|| 8-Imprimir                               ||" << endl;
    cout << "|| 9-Imprimir reverse                       ||" << endl;
    cout << "|| 10-Lista está vazia?                     ||" << endl;
    cout << "|| 11-Tamanho da Lista                      ||" << endl;
    cout << "|| 12-Limpar Lista                          ||" << endl;
    cout << "|| 13-Concatenar Listas                     ||" << endl;
    cout << "|| 14-Fazer uma Cópia                       ||" << endl;
    cout << "|| 15-Copiar Elementos do Array             ||" << endl;
    cout << "|| 16-Verificar se Listas são Iguais        ||" << endl;
    cout << "|| 17-Separar Lista                         ||" << endl;
    cout << "|| 18-Intercalar Listas                     ||" << endl;
    cout << "|| 19-Sair                                  ||" << endl;
    cout << "==============================================" << endl;
    cin >> resp;
    return resp;
}

int main(){

    QX_List *list;
    list = new QX_List();

    int opc = menu();

    while(opc != 19){
        // Se a escolha for 1
            if(opc==1){
                // Lendo a nova chave da lista para ser inserida
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite a chave à ser inserida             ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                list->push_back(chave);
            }

            if(opc == 2){
                cout << list->pop_back() << endl;
            }

            if(opc == 3){
                int chave, n;
                cout << "==============================================" << endl;
                cout << "||Digite a chave à ser inserida             ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                cout << "==============================================" << endl;
                cout << "||Digite a Posição a ser inserida           ||" << endl;
                cout << "==============================================" << endl;
                cin >> n;
                list->insertAfter(chave,n);
            }

            if(opc == 4){
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite a chave à ser Removida             ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                list->remove(chave);
            }

            if(opc == 5){
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite a chave à ser Removida Totalmente  ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                list->removeAll(chave);
            }

            if(opc == 6){
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite a chave do Nó a ser Removido       ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;

                Node *no = new Node;
                no->key = chave;
                list->removeNode(no);
            }

            if(opc == 7){
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite o Termo a ser Removido             ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;

                list->removeNodeAt(chave);
            }

            if(opc == 8){
                list->print();
            }

            if(opc == 9){
                list->printReverse();
            }

            if(opc == 10){
                if(list->isEmpty()){
                    cout << "Lista Vazia" << endl;
                }else{
                    cout << "Lista Povoada" << endl;
                }
            }

            if(opc == 11){
                cout << list->size() << endl;
            }

            if(opc == 12){
                list->clear();
            }

            if(opc == 13){
                QX_List *aux;
                aux = new QX_List();
                cout << "Preencher lista, Digite -1 para parar" <<endl;
                cout << "Digite a chave a ser inserida" << endl;
                int a;
                cin >> a;
                while(a != (-1)){
                    if(a != (-1)){
                    aux->push_back(a);
                    cout << "Digite a chave a ser inserida" << endl;
                    cin >> a;
                    }
                }

                list->concat(aux);
            }

            if(opc == 14){
                QX_List *aux;
                aux = new QX_List();

                aux = list->copy();
                cout << "Lista Original" << endl;
                list->print();
                cout << "Lista Cópia" << endl;
                aux->print();
            }

            if(opc == 15){
                int *v;
                int n;
                cout << "Digite o Tamanho do vetor" << endl;
                cin >> n;
                v = new int[n];
                cout << "preencha o vetor" << endl;
                for(int i=0; i < n; i++ ){
                    cin >> v[i];
                }

                list->copyArray(v,n);
            }

            if(opc == 16){
                QX_List *aux;
                aux = new QX_List();
                cout << "Preencher lista, Digite -1 para parar" <<endl;
                cout << "Digite a chave a ser inserida" << endl;
                int a;
                cin >> a;
                while(a != (-1)){
                    if(a != (-1)){
                    aux->push_back(a);
                    cout << "Digite a chave a ser inserida" << endl;
                    cin >> a;
                    }
                }

                if(list->equal(aux)){
                    cout << "Igual" << endl;
                }else{
                    cout << "Diferente" << endl;
                }

            }

            if(opc ==17){
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite o Termo                            ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                QX_List *aux;
                aux = new QX_List();

                aux = list->separate(chave);
                cout << "Lista Original" << endl;
                list->print();
                cout << "Lista Separada" << endl;
                aux->print();

            }

            if(opc == 18){
                QX_List *aux;
                aux = new QX_List();
                cout << "Preencher lista, Digite -1 para parar" <<endl;
                cout << "Digite a chave a ser inserida" << endl;
                int a;
                cin >> a;
                while(a != (-1)){
                    if(a != (-1)){
                    aux->push_back(a);
                    cout << "Digite a chave a ser inserida" << endl;
                    cin >> a;
                    }
                }

                cout << "Lista Original" << endl;
                list->print();
                cout << "Lista Auxiliar" << endl;
                aux->print();

                list->merge_lists(aux);
                cout << "Lista Intercalada" << endl;
                list->print();
            }




            opc = menu();
    }

}