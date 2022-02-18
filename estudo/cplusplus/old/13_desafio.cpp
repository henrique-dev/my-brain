#include <iostream>
#include <vector>

using namespace std;

int main13()
{
	int valor1 = 0;
	cout << "Digite um valor em cents: ";
	cin >> valor1;

	cout << "O equivalente do valor em dolares é: " << endl;
	cout << "dollars: " << (valor1 / 100) << endl;
	cout << "quarters: " << (valor1 / 25) << endl;
	cout << "dimes: " << (valor1 / 10) << endl;
	cout << "nickels: " << (valor1 / 5) << endl;
	cout << "pennies: " << (valor1 / 1) << endl;

	cout << 12 % 12;

	return 0;
}