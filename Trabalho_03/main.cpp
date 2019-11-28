// THIAGO MARINHO BESERRA
// MATRICULA: 420675

//#include "ordenacaoVetor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void gera_dados(int num_iteracoes, const int vetor_tam[]);
void ler_dados(int n, int A[], const char *nomeArquivo);
void bubbllesortInterativo(int n, int A[]);
void bubblesortRecursivo(int n, int A[]);
void insertionsortInterativo(int n, int v[]);
void insertionsortRecursivo(int n, int v[]);




int main(){


// Os tamanhos dos seis vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'

    // Etapa 1: Gerar arquivos contendo números aleatórios
	gera_dados(TOTAL_N, tam);

	// ------------------------------------------------------------
	// Etapa 1 - Execução do bubblesortInterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs("resultados/resultadoBubbleSortInterativo.txt", std::ofstream::out );

    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o bubble sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// bubbleSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

            bubbllesortInterativo(tamanho_vetor, vetor); // ordena o vetor usando o bubblesort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_bubble += duracao_bubble;
			
		}
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[bubbleSortInterativo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs.close(); // fecha arquivo de resultados do bubble Sort
	// ------------------------------------------------------------

//================================================================================================

	// ------------------------------------------------------------
	// Etapa 2 - Execução do bubblesortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs2("resultados/resultadoBubbleSortRecursivo.txt", std::ofstream::out );

    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o bubble sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// bubbleSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

            bubblesortRecursivo(tamanho_vetor, vetor); // ordena o vetor usando o bubblesort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_bubble += duracao_bubble;
			
		}
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[BubbleSortRecursivo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
		ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs2.close(); // fecha arquivo de resultados do bubble Sort
// 	// ------------------------------------------------------------

//================================================================================================

	// ------------------------------------------------------------
	// Etapa 2 - Execução do InsertionsortInterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs3("resultados/resultadoInsertionsortInterativo.txt", std::ofstream::out );

    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_insertion = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o insertion sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// insertionSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

            insertionsortInterativo(tamanho_vetor, vetor); // ordena o vetor usando o bubblesort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_insertion = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_insertion += duracao_insertion;
			
		}
		
		duracao_media_insertion = duracao_media_insertion / 5.0;
		cout << "[InsertionSortInterativo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertion << " microssegundos" << endl;
		ofs3 << tamanho_vetor << " " << duracao_media_insertion << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs3.close(); // fecha arquivo de resultados do bubble Sort
	// ------------------------------------------------------------

//================================================================================================

	// ------------------------------------------------------------
	// Etapa 4 - Execução do InsertionsortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs4("resultados/resultadoInsertionsortRecursivo.txt", std::ofstream::out );

    for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_insertion = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o insertion sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// insertionSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

            insertionsortRecursivo(tamanho_vetor, vetor); // ordena o vetor usando o bubblesort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_insertion = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_insertion += duracao_insertion;
			
		}
		
		duracao_media_insertion = duracao_media_insertion / 5.0;
		cout << "[InsertionSortRecursivo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertion << " microssegundos" << endl;
		ofs4 << tamanho_vetor << " " << duracao_media_insertion << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs4.close(); // fecha arquivo de resultados do bubble Sort
	// ------------------------------------------------------------


}

void gera_dados(int num_iteracoes, const int vetor_tam[]){
	for(int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[iteracao];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

void ler_dados(int n, int A[], const char *nomeArquivo){	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor
	}
	fin.close(); // fecha o arquivo de leitura
}

void bubbllesortInterativo(int n, int v[]){
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--){
            if (v[j] < v[j - 1]){
                swap(v[j], v[j - 1]);
            }
        }
    }
}

void bubblesortRecursivo(int n, int v[]){
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++){
        if (v[i] > v[i + 1])
            swap(v[i], v[i + 1]);
    }

    bubblesortRecursivo(n - 1,v);
}

void insertionsortInterativo(int n, int v[]){
    int i, j, key;
    for (j = 1; j < n; j++){
        key = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > key){
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}

void insertionsortRecursivo(int n, int v[]){

    if(n <= 1)
        return;
    
    insertionsortRecursivo(n-1, v);

    int ultimo = v[n-1];
    int j = n-2;

    while(j >= 0 && v[j]>ultimo){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = ultimo;

}

void selectionsorttInterativo(int n, int v[]){
    for (int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j<n;j++)
            if(v[j]<v[min])
                min = j;

        swap(v[min],v[i]);    
        
    }
    
}

int minIndex(int v[],int i, int j){
    if(i==j)
        return i;

    int k = minIndex(v,i+1, j);

    return (v[i] < v[k])? i : k;    

}

void selectionsorttRecursivo(int n,int v[], int index){

    if(index == n)
        return;

    int k = minIndex(v,index,n-1);

    if(k!=index)
        swap(v[k],v[index]);

    selectionsorttRecursivo(n,v, index+1);

}