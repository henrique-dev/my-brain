#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159;

// PROTOTIPOS
double calcular_area_circulo(double);
void area_circulo();
double calcular_volume_cilindro(double, double);
void volume_cilindro();

int main22() {
	area_circulo();
	volume_cilindro();

	return 0;
}

// DEFINIÇÕES
double calcular_area_circulo(double raio) {
	return pi * pow(raio, 2);
}

void area_circulo() {
	double raio = 0;
	cout << "\nEntre com o raio do circulo: ";
	cin >> raio;
	cout << "A area do circulo com raio " << raio << " e " << calcular_area_circulo(raio) << endl;
}

double calcular_volume_cilindro(double raio, double altura) {
	return calcular_area_circulo(raio) * altura;
}

void volume_cilindro() {
	double raio = 0;
	double altura = 0;
	cout << "\nEntre com o raio do cilindro: ";
	cin >> raio;
	cout << "\nEntre com a altura do cilindro: ";
	cin >> altura;
	cout << "O volume de um cilindro com raio " << raio << " e altura " << altura <<
		" e " << calcular_volume_cilindro(raio, altura) << endl;
}