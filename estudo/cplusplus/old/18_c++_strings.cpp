// JA FOI USADO
#include <iomanip> // MANIPULAÇÃO DE IO - Ex.: cout << fixed << setprecision(2);
#include <cctype> // Funções para testar caracteres e conversões
#include <cstring> // Funções baseadas em caracteres

// USANDO
#include <iostream>
#include <string>

using namespace std;

int main18() {	
	string valor1;
	cout << valor1 << endl;
	string valor2 = { "Frank" };
	cout << valor2 << endl;
	string valor3 = { valor2 };
	cout << valor3 << endl;
	string valor4 = { "Frank", 3 };
	cout << valor4 << endl;
	string valor5 = { valor3, 0, 2 };
	cout << valor5 << endl;
	string valor6 = { 10, 'X' };
	cout << valor6 << endl;

	cout << "-----------------------------" << endl;
	cout << valor2.substr(0, 2) << endl;

	cout << "-----------------------------" << endl;
	string valor7 = "Paulo Henrique G Bacelar";
	cout << valor7.find("H") << endl;
	cout << valor7.find("Henrique") << endl;
	cout << valor7.find("Hr") << endl;
	cout << valor7.length() << endl;
	valor7.erase(5, 4);
	cout << valor7<< endl;

	cout << "-----------------------------" << endl;
	string valor8;
	//getline(cin, valor8, 'x'); // 'x' change /t para terminar a leitura
	cout << valor8 << endl;

	cout << "-----------------------------" << endl;
	swap(valor2, valor7);
	cout << valor2 << endl;
	cout << valor7 << endl;

	cout << "-----------------------------" << endl;
	string valor9 = "ABCD";
	string valor10 = "BACD";

	cout << (valor9 > valor10) << endl;
	cout << (valor10 > valor9) << endl;

	return 0;
}