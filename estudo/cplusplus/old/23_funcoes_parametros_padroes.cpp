#include <iostream>

using namespace std;

double calcular_custo(double custo_base, double taxa_imposto = 0.06);

int main23() {
	double custo = 0;
	custo = calcular_custo(200.0);
	cout << custo << endl;
	custo = calcular_custo(100.0, 0.08);
	cout << custo << endl;

	return 0;
}

double calcular_custo(double custo_base, double taxa_imposto) {
	return custo_base += (custo_base * taxa_imposto);
}