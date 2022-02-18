#include <iostream>
#include <iomanip> // MANIPULAÇÃO DE IO - Ex.: cout << fixed << setprecision(2);
#include <cctype> // Funções para testar caracteres e conversões
#include <cstring> // Funções baseadas em caracteres

using namespace std;

int main17() {

	char first_name[20];
	char last_name[20];
	char full_name[100];
	char temp[100];

	//cout << first_name << endl;

	cout << "Please enter your first name: ";
	cin >> first_name;

	cout << "Please enter your last name: ";
	cin >> last_name;

	cout << "Hello " << first_name << " your first name has " << strlen(first_name) << " characteres" << endl;
	cout << "and your last name " << last_name << " has " << strlen(last_name) << " characteres" << endl;

	strcpy_s(full_name, first_name);
	strcat_s(full_name, " ");
	strcat_s(full_name, last_name);
	cout << "Your full name is " << full_name << endl;

	cout << "-------------------------------" << endl;
	cout << "Enter your full name: ";
	cin >> full_name;
	cout << "Your full name is " << full_name << endl;

	cout << "-------------------------------" << endl;
	cout << "Enter your full name: ";
	cin.getline(full_name, 50);
	cout << "Your full name is " << full_name << endl;


	return 0;
}