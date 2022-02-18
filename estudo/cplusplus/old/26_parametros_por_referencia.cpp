#include <iostream>
#include <vector>

using namespace std;

void trocar(int&, int&);
void passagem_por_referencia1(int&);
void passagem_por_referencia2(string&);
void passagem_por_referencia3(vector<string>&);
void imprimir_vetor(vector<string>&);

int main26() {
	//int x = 10, y = 20;
	//cout << x << " " << y << endl;
	//trocar(x, y);
	//cout << x << " " << y << endl;

	int num = 10;

	cout << "Numero antes da função: " << num << endl;
	passagem_por_referencia1(num);
	cout << "Numero depois da função: " << num << endl;

	string msg = "Paulo Henrique";
	cout << "Mensagem antes da função: " << msg << endl;
	passagem_por_referencia2(msg);
	cout << "Mensagem depois da função: " << msg << endl;

	vector<string> nome_completo = {"Paulo", "Henrique"};
	imprimir_vetor(nome_completo);
	passagem_por_referencia3(nome_completo);
	imprimir_vetor(nome_completo);


	return 0;
}

void trocar(int &a, int &b) {
	cout << "[ " << &a << " ]";
	cout << "[ " << &b << " ]" << endl;
	int temp = a;
	a = b;
	b = temp;
}

void passagem_por_referencia1(int &num) {
	num = 1000;
}

void passagem_por_referencia2(string &s) {
	s = "Changed";
}

void passagem_por_referencia3(vector<string> &v) {
	v.clear();
}

void imprimir_vetor(vector<string>& v) {
	for (auto s : v) {
		cout << s << " ";
	}
	cout << endl;
}