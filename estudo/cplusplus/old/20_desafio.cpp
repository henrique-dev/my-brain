// JA FOI USADO
#include <iomanip> // MANIPULAÇÃO DE IO - Ex.: cout << fixed << setprecision(2);
#include <cctype> // Funções para testar caracteres e conversões
#include <cstring> // Funções baseadas em caracteres

// USANDO
#include <iostream>
#include <string>

using namespace std;

int main20() {

	cout << "Informe os caracteres que a piramide ira conter: " << endl;
	string texto;
	getline(cin, texto);

	for (int i = 0; i < texto.length(); i++) {
		for (int k = 0; k < (texto.length() - i); k++) {
			cout << " ";
		}
		bool voltando = false;
		for (int j=0; j!=-1;) {
			if (j >= i || voltando) {				
				cout << texto[j];
				j--;
				voltando = true;
			} else {
				cout << texto[j];
				j++;
			}
		}
		cout << endl;
	}
	return 0;
}