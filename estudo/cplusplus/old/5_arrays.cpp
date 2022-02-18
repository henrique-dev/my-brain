#include <iostream>

int main5() 
{

	std::cout << "int valor1[5];" << std::endl;
	int valor1[5];
	for (int i = 0; i < 5; i++) {
		std::cout << valor1[i] << std::endl;
	}

	std::cout << "int valor2[10];" << std::endl;
	int valor2[10];
	for (int i = 0; i < 10; i++) {
		std::cout << valor2[i] << std::endl;
	}
	
	std::cout << "const int valor3 = 365; int valor4[valor3];" << std::endl;
	const int valor3 = 365;
	int valor4[valor3];
	for (int i = 0; i < valor3; i++) {
		std::cout << valor4[i] << std::endl;
	}

	std::cout << "int valor5[5] = { 1, 2, 3, 4, 5 };" << std::endl;
	int valor5[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		std::cout << valor5[i] << std::endl;
	}

	std::cout << "int valor6[5] = { 3, 5 };" << std::endl;
	int valor6[5] = { 3, 5 };
	for (int i = 0; i < 5; i++) {
		std::cout << valor6[i] << std::endl;
	}

	std::cout << "const int valor7 = 365; double valor8[valor7] { 0 };" << std::endl;
	const int valor7 = 365;
	double valor8[valor7] { 0 };
	for (int i = 0; i < valor7; i++) {
		std::cout << valor8[i] << std::endl;
	}

	std::cout << "int valor9[] = { 1, 2, 3, 4, 5 };" << std::endl;
	int valor9[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		std::cout << valor9[i] << std::endl;
	}

	std::cout << "int valor10[10] = {};" << std::endl;
	int valor10[10] = {};
	for (int i = 0; i < 10; i++) {
		std::cout << valor10[i] << std::endl;
	}


	return 0;
}