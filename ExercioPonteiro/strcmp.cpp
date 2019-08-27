#include <iostream>
using namespace std;

int tamanho(char *str){
    int cont=0;
    for(int i=0; str[i] != '\0'; i++){
        cont++;
    }
    return cont;
}

int strcmp(char *str1,char *str2){
        if(tamanho(str1) > tamanho(str2))
            return 1;
        else if(tamanho(str1) < tamanho(str2))   
            return -1;
        else{
            for(int i=0;i<tamanho(str1);i++){
                if(str1[i]>str2[i])
                    return 1;
                else if(str2[i]>str1[i])
                    return -1;        
            }
            return 0;
        }   

}



int main(){
    char *str1 = new char[50];
    char *str2 = new char[50];

    cin.getline(str1,50);
    cin.getline(str2,50);

    cout << strcmp(str1,str2) << endl;
}