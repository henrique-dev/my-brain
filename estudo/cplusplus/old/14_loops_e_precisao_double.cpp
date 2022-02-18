#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main14()
{
	for (auto valor : { 0, 1, 2, 3, 4, 5 }) {
		cout << valor << endl;
	}

	double valor1 = 10;
	const int valor2 = 3;
	cout << fixed << setprecision(2);
	cout << valor1 / valor2 << endl;

	for (auto valor : "Paulo Henrique Goncalves Bacelar") {
		if (valor == ' ')
			cout << '\t';
		else
			cout << valor;
	}

	return 0;
}