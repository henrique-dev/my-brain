#include <iostream>

int main6() 
{

	const int rows = 3;
	const int cols = 4;
	
	int valor1[rows][cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << valor1[i][j] << std::endl;
		}
	}

	std::cout << "===============================" << std::endl;

	int valor2[rows][cols] = {
		{0, 4, 3, 5},
		{2, 3, 3, 5},
		{1, 4, 4, 5}
	};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << valor2[i][j] << std::endl;
		}
	}

	std::cout << "===============================" << std::endl;

	int valor3[rows][cols] = {};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << valor3[i][j] << std::endl;
		}
	}

	return 0;
}