#include <iostream>
#include "QX_SeqList.h"
using namespace std;

int main(){
    QX_SeqList list(7);

   //adicionei  
    list.push_back(2);
    list.push_back(3);
    list.push_back(2);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    
    // Tamanho da Lista
    cout << "Tamanho da List: " << list.size() << endl;

    //se lista vazia
    if(list.isEmpty())
        cout << "Lista vazia" << endl;
    else
        cout << "Lista não vazia" << endl;

    // buscar chave 4
    cout << "busca por chave " << list.search(5) << endl;

    //buscar elemento
    cout << "busca elemento "<< list.at(5) << endl;

    // Print
    cout << "Print" << endl;
    list.print();

    // Print reverse
    cout << "Print Reverse" << endl;
    list.printReverse();

    //remover elemento
    cout << "removendo o 5" << endl;
    list.remove(5);

    //print
    cout << "Print" << endl;
    list.print();

    //remover todos elemento
    cout << "removendo todos os numeros 2" << endl;
    list.removeAll(2);

    cout << "Print" << endl;
    list.print();

    cout << "removendo o ultimo elemento" << endl;
    list.pop_back();

    cout << "Print" << endl;
    list.print();

    cout << "limpando a lista" << endl;
    list.clear();

    cout << "Print" << endl;
    list.print();

    list.~QX_SeqList();
}