#include <iostream>

using namespace std;

void imprimir_array(const string[], size_t);
void modificar_array(string[], size_t, size_t, string);

int main25() {

	string valores[] = {
		"Paulo Henrique",
		"Nathallye Tabaresu"
	};
	size_t tamanho_array = 2;

	imprimir_array(valores, tamanho_array);
	modificar_array(valores, tamanho_array, 10, "PH");
	imprimir_array(valores, tamanho_array);
	modificar_array(valores, tamanho_array, 1, "PH");
	imprimir_array(valores, tamanho_array);
	modificar_array(valores, tamanho_array, 0, "NT");
	imprimir_array(valores, tamanho_array);

	return 0;
}

void imprimir_array(const string s[], size_t v) {
	cout << "[ ";
	for (size_t i = 0; i < v; i++) {
		cout << s[i];
		if (i < v-1) {
			cout << ", ";
		}
	}
	cout << " ]";
	cout << endl;
}

void modificar_array(string s[], size_t v, size_t i, string ns) {
	if (i < v) {
		s[i] = ns;
	}
}