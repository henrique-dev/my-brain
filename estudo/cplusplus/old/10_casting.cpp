#include <iostream>

using namespace std;

int main10()
{
	int valor1 = 100;
	int valor2 = 8;
	double valor3 = 0.0;

	valor3 = valor1 / valor2;

	cout << valor3 << endl;

	valor3 = static_cast<double>(valor1) / valor2;

	cout << valor3 << endl;

	//valor3 = (double)valor1 / valor2; // C OLD STYLE

	cout << valor3 << endl;

	cout << (100 == (50 + 50)) << endl;
	//cout << boolalpha;

	cout << (100 == (50 + 50)) << endl;
	//cout << noboolalpha;

	return 0;
}