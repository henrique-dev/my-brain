#include <iostream>
#include <vector>

using namespace std;

/*
* O RETORNO NÃO É CONSIDERADO COMO DIFERENTE
*/

void imprimir(int n);
void imprimir(double d);
void imprimir(string s);
void imprimir(vector<int> v);
void imprimir(vector<string> v);

int main24() {
	imprimir(1);
	imprimir(1.0);
	imprimir("PAULO HENRIQUE");
	imprimir(vector<int> {0, 1, 2, 3, 4});
	imprimir(vector<string> {"PAULO", "HENRIQUE", "GONCALVES", "BACELAR"});
	return 0;
}

void imprimir(int n) {
	cout << "Imprimindo int: " << n << endl;
}

void imprimir(double d) {
	cout << "Imprimindo double: " << d << endl;
}

void imprimir(string s) {
	cout << "Imprimindo string: " << s << endl;
}

void imprimir(vector<int> v) {
	cout << "Imprimindo vector<int>: " << endl;
	for (auto n : v) {
		cout << n << " ";
	}
	cout << endl;
}

void imprimir(vector<string> v) {
	cout << "Imprimindo vector<string>: " << endl;
	for (auto s : v) {
		cout << s << " ";
	}
	cout << endl;
}