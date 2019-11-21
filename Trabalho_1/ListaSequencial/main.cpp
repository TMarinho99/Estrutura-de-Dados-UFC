//THIAGO MARINHO BESERRA
//MATRICULA == 420675

#include <iostream>
#include <climits>
#include "QX_SeqList.h"
using namespace std;

//Menu do Programa
int menu(){
    int resp;
    cout << "==============================================" << endl;
    cout << "|| 1-Criar Elemento                         ||" << endl;
    cout << "|| 2-Buscar Indice do Elemento              ||" << endl;
    cout << "|| 3-Buscar N-ésimo termo                   ||" << endl;
    cout << "|| 4-Imprimir Lista                         ||" << endl;
    cout << "|| 5-Imprimir Lista Inversamente            ||" << endl;
    cout << "|| 6-Remover Primeiro Elemento 'x' da Lista ||" << endl;
    cout << "|| 7-Remover Todos os Elementos 'x' da Lista||" << endl;
    cout << "|| 8-Remover o Ultimo elemento da Lista     ||" << endl;
    cout << "|| 9-Tamanho da Lista                       ||" << endl;
    cout << "|| 10-Lista está vazia?                     ||" << endl;
    cout << "|| 11-Limpar Lista                          ||" << endl;
    cout << "|| 12=Sair                                  ||" << endl;
    cout << "==============================================" << endl;
    cin >> resp;
    return resp;
}

int main(){
    cout << "Olá, Digite o Tamanho da Lista" << endl;
    
    // tamanho da Lista
    int tamanho;
    cin >> tamanho;


    // Criando a Listas
    QX_SeqList list(tamanho);
    
    
    // pegando a escolha do usuario para o menu
    int opc = menu();

        //Enquanto o usuario nao digitar o numero correspondente para sair o programa fica rodando
        while(opc!=12){
            
            // Se a escolha for 1
            if(opc==1){
                // Lendo a nova chave da lista para ser inserida
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite a chave à ser inserida             ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                list.push_back(chave);
                
            }
            // se a esclha for 2
            if (opc==2){
                // lendo a chave para ser buscada
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite a chave a ser Buscada              ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                    if(list.search(chave) != INT_MIN )
                        cout << list.search(chave) << endl;
                    else{
                        cout << "==============================================" << endl;
                        cout << "||Numero Não Encontrado                     ||" << endl;
                        cout << "==============================================" << endl;
                    }                                
            }
            //se a opcao for 3
            if(opc==3){
                // lendo o termo a ser buscado
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite o Termo a ser Buscada              ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                if(list.at(chave) != INT_MIN )
                        cout << list.at(chave) << endl;
                    else{
                        cout << "==============================================" << endl;
                        cout << "||Termo Não Encontrado                      ||" << endl;
                        cout << "==============================================" << endl;
                    }
            }
            //se a opcao for 4
            if(opc==4){
                // chamo o metodo de imprimir
                list.print();
            }
            //se a opcao for 5
            if(opc==5){
                // chamo o metodo de imprimir reverso
                list.printReverse();
            }
            //se a opcao for 6
            if(opc==6){
                // lend o elemento a ser removido e removendo logo depois
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite o Elemento a ser Removido          ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                list.remove(chave);
                                
            }
            //se a opcao for 7
            if(opc==7){
                // lendo o elemento a ser removido totalmente da lista
                int chave;
                cout << "==============================================" << endl;
                cout << "||Digite o Elemento a ser Removido          ||" << endl;
                cout << "==============================================" << endl;
                cin >> chave;
                list.removeAll(chave);
                
            }
            //se a opcao for 8
            if(opc==8){
                // chamando o metodo que remove o ultimo elemento da lista
                list.pop_back();
            }
            //se a opcao for 9
            if(opc==9){
                // chamando o metodo que retorna o tamanho da ista
                cout << list.size() << endl;                
            }
            //se a opcao for 10
            if(opc==10){
                // verificando se a lista esta vazia
                if(list.isEmpty()){
                    cout << "==============================================" << endl;
                    cout << "||Lista Vazia                               ||" << endl;
                    cout << "==============================================" << endl;
                }else{
                    cout << "==============================================" << endl;
                    cout << "||Lista Povoada                             ||" << endl;
                    cout << "==============================================" << endl;
                }          
            }
            //se a opcao for 11
            if(opc==11){
                //chamando o metodo que limpa a lista
                list.clear();
                    cout << "==============================================" << endl;
                    cout << "||A Lista foi Limpa                         ||" << endl;
                    cout << "==============================================" << endl;
            }
                


            // verificando novamente o menu de opçoes
            opc = menu();
        }
    


}

