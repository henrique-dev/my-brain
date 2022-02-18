#include <iostream>
#include <iomanip> // MANIPULAÇÃO DE IO - Ex.: cout << fixed << setprecision(2);
#include <cctype> // Funções para testar caracteres e conversões

using namespace std;

int main16() {
	char valor1 = 'A';
	char valor2 = 'b';
	
	// TESTE DE CARACTERES
	cout << "TESTE DE CARACTERES" << endl;
	cout << isalpha(valor1) << endl; // se é letra
	cout << isalnum(valor1) << endl; // se é letra ou digito
	cout << isdigit(valor1) << endl; // se é digito
	cout << islower(valor1) << endl; // se é minusculo
	cout << isprint(valor1) << endl; // se é imprimivel
	cout << ispunct(valor1) << endl; // se é pontuação
	cout << isupper(valor1) << endl; // se é maiusculo
	cout << isspace(valor1) << endl; // se é espaço
	
	// CONVERSÃO DE CARACTERES
	cout << endl << "CONVERSÃO DE CARACTERES" << endl;
	cout << static_cast<char>(tolower(valor1)) << endl;
	cout << static_cast<char>(toupper(valor2)) << endl;
	

	return 0;
}