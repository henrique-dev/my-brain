#include <iostream>
#include <vector>

using namespace std;

int main11()
{
	//int valor1[10]{100};
	vector<int> valor1(10, 100);

	valor1[0] += 1;
	valor1[1] -= 1;
	valor1[2] *= 1;
	valor1[3] /= 1;
	valor1[4] %= 1;
	valor1[5] >>= 1;
	valor1[6] <<= 1;
	valor1[7] &= 1;
	valor1[8] ^= 1;
	valor1[9] |= 1;

	for (int valor : valor1) {
		cout << valor << endl;
	}

	return 0;
}