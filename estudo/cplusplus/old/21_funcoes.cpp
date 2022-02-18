#include <iostream>
#include <cmath>

using namespace std;

/*const double pi = 3.14159;

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
}*/

int main21() {

	double numero = 0;
	cout << "Digite um numero (double): ";
	//cin >> numero;

	cout << "A raiz quadrada de " << numero << " e " << sqrt(numero) << endl;
	cout << "A raiz cubica de " << numero << " e " << cbrt(numero) << endl;

	cout << "O seno de " << numero << " e " << sin(numero) << endl;
	cout << "O cosseno de " << numero << " e " << cos(numero) << endl;

	cout << "O teto de " << numero << " e " << ceil(numero) << endl;
	cout << "O piso de " << numero << " e " << floor(numero) << endl;
	cout << "O arredondamento de " << numero << " e " << round(numero) << endl;

	double potencia = 0;
	cout << "\nEntre com uma potencia de " << numero << " para: ";
	//cin >> potencia;
	cout << numero << " elevado a " << potencia << " e " << pow(numero, potencia) << endl;

	int numero_aleatorio = 0;
	size_t contador = 10;
	int minimo = 1;
	int maximo = 6;
	
	// semear o gerador de numeros aleatorios, senão sempre ira vir os mesmos numeros
	cout << "RAND_MAX no seu sistema e: " << RAND_MAX << endl;
	srand(time(nullptr));

	for (size_t i = 1; i <= contador; i++) {
		numero_aleatorio = rand() % maximo + minimo;
		cout << rand() << " => ";
		cout << numero_aleatorio << endl;
	}

	cout << endl << endl;

	//area_circulo();
	//volume_cilindro();

	return 0;
}