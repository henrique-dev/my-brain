#include <iostream>

using namespace std;

void exemplo_variavel_local_estatica(int x);

/*
* VARIAVEIS ESTATICAS DE FUNÇÕES SÓ SÃO INICIALIZADAS UMA VEZ
*/
int main27() {

	exemplo_variavel_local_estatica(50);
	exemplo_variavel_local_estatica(50);
	exemplo_variavel_local_estatica(50);
	exemplo_variavel_local_estatica(50);
	exemplo_variavel_local_estatica(50);

	return 0;
}

void exemplo_variavel_local_estatica(int x) {
	static int valor = 0;
	cout << "\nValor da variavel local estatica: " << valor << " [V]";
	valor += x;
	cout << "\nValor da variavel local estatica: " << valor << " [A]\n";
	cout << "--------------------------------------------------------";
}