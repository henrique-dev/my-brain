// JA FOI USADO
#include <iomanip> // MANIPULAÇÃO DE IO - Ex.: cout << fixed << setprecision(2);
#include <cctype> // Funções para testar caracteres e conversões
#include <cstring> // Funções baseadas em caracteres

// USANDO
#include <iostream>
#include <string>

using namespace std;

int main19() {
	
	string mensagem;
	cout << "Insira a mensagem para criptografar: ";
	getline(cin, mensagem);

	string mensagemCriptografada = "";
	string mensagemDescriptografada = "";
	int caractere_inicial = 'a';
	int caractere_crip_inicial = 'x';
	//int diferenca = caractere_crip_inicial - caractere_inicial;
	//cout << caractere_inicial;
	for (char c : mensagem) {
		int diferenca = c - caractere_inicial;
		int c_convertido = caractere_crip_inicial + diferenca;
		//cout << "[ " << static_cast<int>(c) << "] [ " << static_cast<int>(c_convertido) << " ] -> " << c << " = " << static_cast<char>(c_convertido) << endl;
		mensagemCriptografada += static_cast<char>((c_convertido));
	}

	cout << endl << "Segue a mensagem criptograda: " << endl;
	cout << mensagemCriptografada << endl << endl;
	cout << "Descriptografando a mensagem... " << endl;

	for (char c : mensagemCriptografada) {
		int diferenca = c - caractere_crip_inicial;
		int c_convertido = caractere_inicial + diferenca;
		//cout << "[ " << static_cast<int>(c) << "] [ " << static_cast<int>(c_convertido) << " ] -> " << c << " = " << static_cast<char>(c_convertido) << endl;
		mensagemDescriptografada += static_cast<char>((c_convertido));
	}

	cout << "Segue a mensagem descriptograda: " << endl;
	cout << mensagemDescriptografada << endl;



	return 0;
}