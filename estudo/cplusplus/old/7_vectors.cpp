#include <iostream>
#include <vector>

/*
* Os vetores fazem parte da biblioteca padrão
*/
int main7() 
{

	/*
	* 1D VECTORS
	*/
	std::cout << "2D VECTORS" << std::endl;
	std::vector <char> valor1;
	std::vector <int> valor2;

	std::vector <char> valor3 (5);
	std::vector <int> valor4 (10);
	std::vector <int> valor5 = {1};	
	
	std::cout << valor3.size() << std::endl;
	std::cout << valor4.size() << std::endl;
	std::cout << valor4.at(0) << std::endl;
	std::cout << valor5.size() << std::endl;
	std::cout << valor5.at(0) << std::endl;

	std::cout << "-----------------------" << std::endl;
	std::vector <char> valor6 = { 'a', 'e', 'i', 'o', 'u' };
	std::vector <int> valor7 = { 100, 98 , 89, 85, 93 };
	std::vector <double> valor8 (365, 80.0);

	std::cout << valor6.size() << std::endl;
	std::cout << valor7.size() << std::endl;
	std::cout << valor7.at(0) << std::endl;
	std::cout << valor8.size() << std::endl;
	std::cout << valor8.at(0) << std::endl;
	std::cout << valor8.at(1) << std::endl;
	std::cout << valor8.at(2) << std::endl;

	for (unsigned int i = 0; i < valor6.size(); i++) {
		std::cout << valor6[i] << std::endl;
	}

	std::cout << "-----------------------" << std::endl;
	for (unsigned int i = 0; i < valor6.size(); i++) {
		std::cout << valor6.at(i) << std::endl;
	}

	std::cout << "-----------------------" << std::endl;
	valor6[0] = 'A';
	valor6.at(1) = 'E';

	for (unsigned int i = 0; i < valor6.size(); i++) {
		std::cout << valor6.at(i) << std::endl;
	}

	std::cout << "-----------------------" << std::endl;
	valor6.push_back('B');
	for (unsigned int i = 0; i < valor6.size(); i++) {
		std::cout << valor6.at(i) << std::endl;
	}

	std::cout << "-----------------------" << std::endl;
	/*
	* 2D VECTORS
	*/
	std::cout << "MULTI-D VECTORS" << std::endl;
	std::vector <std::vector<int>> valor9 (0);
	for (unsigned int i = 0; i < valor9.size(); i++) {
		for (unsigned int j = 0; j < valor9.at(i).size(); j++) {
			std::cout << valor9.at(i).at(j) << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;

	std::vector <std::vector<int>> valor10 = {
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};
	for (unsigned int i = 0; i < valor10.size(); i++) {
		for (unsigned int j = 0; j < valor10.at(i).size(); j++) {
			std::cout << valor10.at(i).at(j) << std::endl;
			std::cout << valor10[i][j]<< std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;

	return 0;
}