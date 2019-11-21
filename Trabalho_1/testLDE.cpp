#include <iostream>
#include "QX_List.h"
using namespace std;

    int main(){
        QX_List *lista;

        lista = new QX_List();

        lista->print();
        lista->push_back(1);
        lista->push_back(2);
        lista->push_back(3);
        lista->push_back(2);
        lista->push_back(4);
        cout << lista->size() << endl;
        lista->print();
        lista->printReverse();
        cout << "chave removida: "<< lista->pop_back() << endl;
        lista->print();
        lista->insertAfter(10,1);
        lista->print();
        lista->remove(10);
        lista->print();
        cout << "removeAlL" << endl;
        lista->removeAll(2);
        lista->print();
        Node *nox = new Node;
        nox->key = 3;
        lista->removeNode(nox);
        lista->print();
        cout << lista->removeNodeAt(1) << endl;
        lista->print();
        lista->push_back(1);
        lista->push_back(2);
        lista->push_back(3);
        lista->push_back(2);
        lista->push_back(4);
        lista->printReverse();
        lista->clear();
        lista->print();


        QX_List *lst;
        lst = new QX_List();
        cout << "passou" << endl;
        lst->push_back(5);
        lst->push_back(6);
        lst->push_back(7);
        lst->push_back(8);
        lst->push_back(9);

        lista->push_back(1);
        lista->push_back(2);
        lista->push_back(3);
        lista->push_back(2);
        lista->push_back(4);

        lst->print();
        lista->print();
        cout << "concatenando" << endl;
        lista->concat(lst);
        lista->print();

       QX_List *test;
       test = new QX_List();

       test = lista->copy();
       test->print();

       int n = 5;
       int *v;
       v = new int[n];
        for(int i=0; i < n; i++ ){
            v[i] = i;
        }
    cout << "Estou aqui" << endl;
        lista->copyArray(v,n);
        lista->print();


        cout << " == ou != " << endl;

        lista->clear();
        cout << " Passou " << endl;
        
        QX_List *test2;
       test2 = new QX_List();

        test2->push_back(1);
        test2->push_back(2);
        test2->push_back(3);
        test2->push_back(2);
        test2->push_back(4);

        cout << " preencheu test2 " << endl;

        lista->push_back(1);
        lista->push_back(2);
        lista->push_back(3);
        lista->push_back(2);
        lista->push_back(4);

        cout << " Preencheu lista" << endl;

        if(lista->equal(test2)){
            cout << "igual" << endl;
        }else{
            cout << " diferente" << endl;
        }

        test2->clear();
        cout << " Limpou" << endl;
        test2 = lista->separate(2);
        cout << " Separou " << endl;
        test2->print();
        lista->print();

        test2->clear();
        lista->clear();

        test2->push_back(1);
        test2->push_back(2);
        test2->push_back(3);
        test2->push_back(4);
        test2->push_back(5);

        lista->push_back(6);
        lista->push_back(7);
        lista->push_back(8);
        lista->push_back(9);
        lista->push_back(0);


        cout << "===merge===" << endl;

        lista->merge_lists(test2);

        lista->print();


    }