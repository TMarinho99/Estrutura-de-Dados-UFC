#include <iostream>
#include <cstring>
using namespace std;

void imprime_digitos(int n, int k, char v[], int index) {
	int size = strlen(v);
	
	if(size == k) {
		cout << v << endl;
		return;
	}
	
	for(int i = index; i <= n; i++) {
		v[size] = i+'0';
		v[size+1] = '\0';
		imprime_digitos(n, k, v, i+1);
		v[size] = '\0';
	}
}

int main() {
	int n, k;
	cin >> n;
	cin >> k;
	char v[k+1];
	v[0] = '\0';
	imprime_digitos(n, k, v, 1);
	return 0;
}
