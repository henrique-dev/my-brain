#include <iostream>
#include <iomanip> // MANIPULA��O DE IO - Ex.: cout << fixed << setprecision(2);
#include <cctype> // Fun��es para testar caracteres e convers�es

using namespace std;

int main16() {
	char valor1 = 'A';
	char valor2 = 'b';
	
	// TESTE DE CARACTERES
	cout << "TESTE DE CARACTERES" << endl;
	cout << isalpha(valor1) << endl; // se � letra
	cout << isalnum(valor1) << endl; // se � letra ou digito
	cout << isdigit(valor1) << endl; // se � digito
	cout << islower(valor1) << endl; // se � minusculo
	cout << isprint(valor1) << endl; // se � imprimivel
	cout << ispunct(valor1) << endl; // se � pontua��o
	cout << isupper(valor1) << endl; // se � maiusculo
	cout << isspace(valor1) << endl; // se � espa�o
	
	// CONVERS�O DE CARACTERES
	cout << endl << "CONVERS�O DE CARACTERES" << endl;
	cout << static_cast<char>(tolower(valor1)) << endl;
	cout << static_cast<char>(toupper(valor2)) << endl;
	

	return 0;
}