#include <iostream>
#include <vector>

using namespace std;

int main15()
{
	char opcao = ' ';
	vector<int> listaInteiros(0);

	do {
		cout << "=================================" << endl;
		cout << "P - Imprimir os numeros" << endl;
		cout << "A - Adiconar um numero" << endl;
		cout << "M - Mostrar a média dos numeros" << endl;
		cout << "S - Mostrar o menor numero" << endl;
		cout << "L - Mostrar o maior numero" << endl;
		cout << "Q - Sair" << endl << endl;
		cout << "Escolha a opcao: ";
		cin >> opcao;

		switch (opcao) {
			case 'p':
			case 'P': {
				for (int valor : listaInteiros) {
					cout << "[ " << valor << "] ";
				}
				cout << endl;
				break;
			}
			case 'a':
			case 'A': {
				int valor;
				cout << "Insira o numero para adicionar: ";
				cin >> valor;
				listaInteiros.push_back(valor);
				break;
			}		
			case 'm':
			case 'M': {
				if (listaInteiros.size() > 0) {
					double soma = 0;
					for (int valor : listaInteiros) {
						soma += valor;
					}
					cout << "A média dos numeros existentes é : " << soma / listaInteiros.size() << endl;
				}
				else {
					cout << "Nao existe numero na lista" << endl;
				}
				break;
			}
			case 's':
			case 'S': {
				if (listaInteiros.size() > 0) {
					int menorValor = listaInteiros.at(0);
					for (int valor : listaInteiros) {
						if (valor < menorValor) {
							menorValor = valor;
						}
					}
					cout << "O menor valor dos numeros é :" << menorValor << endl;
				}
				else {
					cout << "Nao existe numero na lista" << endl;
				}
				break;
			}
			case 'l':
			case 'L': {
				if (listaInteiros.size() > 0) {
					int maiorValor = listaInteiros.at(0);
					for (int valor : listaInteiros) {
						if (valor > maiorValor) {
							maiorValor = valor;
						}
					}
					cout << "O maior valor dos numeros é :" << maiorValor << endl;
				}
				else {
					cout << "Nao existe numero na lista" << endl;
				}
				break;
			}
		}

	} while (!(opcao == 'Q' || opcao == 'q'));

	return 0;
}