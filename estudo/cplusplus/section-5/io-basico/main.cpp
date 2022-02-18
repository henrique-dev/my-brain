#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    cout << "Hello";
    cout << "World" << endl;
    cout << "Hello World\n";
    cout << "Hello\nOut\nWorld\n";

    int num1;
    int num2;
    double num3;

    cout << "Entre com um numero inteiro: ";
    cin >> num1;
    cout << "O numero e: " << num1 << endl;

    cout << "Entre com dois numeros inteiros separados por espaco: ";
    cin >> num1 >> num2;
    cout << "Os numeros sao: " << num1 << " e " << num2 << endl;

    cout << num1;
    cout << num2;
    

    return 0;
}