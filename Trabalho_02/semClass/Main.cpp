// thiago marinho beserra
// matricula: 420675

#include "Arvore.h"
#include <iostream>
#include <queue>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream leitura("vetores.txt");
    ofstream escrita;
    queue<NoArv *> p;
    int n, maior;

    // n = primeiro numero do arquivo
    leitura >> n;


    while (n != 0)
    {   
            maior =0;
            int aux = 1, numNos;
                while (pow(2, aux) < n){
                aux++;
                }
            numNos = pow(2, aux);
        int *v = new int[numNos];
            // preencho o vetor com a proxima linha do arquivo
            for (int i = 0; i < n; i++)
            {
                leitura >> v[i];
            }

            // coloco os elementos do vetor numa fila e procuro quem é o maior e logo depois incremento
            for (int i = 0; i < n; i++)
            {
                
                NoArv *a = arv_cria(v[i], NULL, NULL);
                p.push(a);
                if (v[i] > maior)
                    maior = v[i];
            }
            maior++;

            // crio a variavel altura
            int altura = ceil(log2(n)) + 1;


            // calculo o tamanho de folhas que a arvore terá e logo depois insiro na fila
            // os numeros que faltam para a arvore ser cheia
            
            for (int i = n; i < numNos; i++)
            {
                v[i] = maior;
                NoArv *a = arv_cria(maior, NULL, NULL);
                p.push(a);
            }

            //cout << "imprimindo o vetor " << n << " altura " << altura << endl;
            

        // essa função é responsavel pelo complemento da arvore
        // o primeiro laço execulta o numero de vezes que o primeiro vetor tem de elementos
        // o segundo execulta de acordo com a altura da arvore 
        // o segundo laço é responsavel por colocar o menor nó na raiz fazendo assim a ordenação
        // o terceiro laço é responsavel por criar o pai dos nós incrementando de 2 em 2
        // e inserindo os novos nós na fila.
        // como o tamanho da fila foi pegue antes do for, então os novos nós poderam ser inseridos
        // sem causar erros no processo

        for(int i=0;i<n;i++){
            
            for(int i = 0;i<altura;i++){
                int tamanho = p.size();
                for(int j=0;j<tamanho-1;j++){
                        NoArv *a1 = p.front();
                        //cout << "esq" << endl;
                        //cout << getChave(a1) << endl;
                        p.pop();
                        NoArv *a2 = p.front();
                        //cout << "dir" << endl;
                        //cout << getChave(a2) << endl;
                        p.pop();
                        int chave = noMenor(a1,a2);

                        NoArv *novo = arv_cria(chave,a1,a2);
                        p.push(novo);
                        j++;
                }
            }

            escrita.open("ordenados.txt", ios::app);
            if(getChave(p.front()) != maior)
                escrita << getChave(p.front()) << " ";
            escrita.close();
            //cout << getChave(p.front()) << " ";
            alterarChave(arv_procurar_no(p.front(), getChave(p.front())), maior);
            alterarChaveVetor(v,numNos,getChave(p.front()),maior);
            //cout << "alterando a chave" << endl;
            

            p.pop();
            for(int i=0;i<numNos;i++){
                NoArv *a = arv_cria(v[i], NULL, NULL);
                p.push(a);
            }
            

        }
        escrita.open("ordenados.txt", ios::app);
        escrita << endl;
        escrita.close();
        leitura >> n;



    }
    leitura.close();
    cout << "FIM" << endl;
    arv_libera(p.front());
}