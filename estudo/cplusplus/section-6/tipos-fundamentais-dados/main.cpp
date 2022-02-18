#include <iostream>

using namespace std;

int main()
{
    /*
    * CARACTERS
    */
    cout << "<===========================>" << endl;
    cout << "EXEMPLO CARACTERS" << endl;
    char valor1 {'a'}; // 1 byte exato. Ao menos 8 bits
    cout << valor1 << endl;
    char16_t valor2 {'ab'}; // Ao menos 16 bits
    cout << valor2 << endl;
    char32_t valor3 {'abcd'}; // Ao menos 32 bits
    cout << valor3 << endl;
    wchar_t valor4 {'A'}; // Pode representar o maior caracter disponivel
    cout << valor4 << endl;

    /*
    * INTEIROS
    */
    // negativos e positivos 
    cout << "<===========================>" << endl;
    cout << "EXEMPLO INTEIROS negativos e positivos" << endl;
    short valor5 {1}; // signed short int valor5; // Ao menos 16 bits
    cout << valor5 << endl;
    int valor6 {65}; // signed int valor6; // Ao menos 16 bits
    cout << valor6 << endl;
    long valor7 {20610000}; // signed long int valor7; // Ao menos 32 bits
    cout << valor7 << endl;
    long long valor8 {7'600'000'000}; // signed long long int valor8; // Ao menos 64 bits
    cout << valor8 << endl;

    cout << "EXEMPLO INTEIROS positivos" << endl;
    // somente positivos
    unsigned short valor9 {2}; // unsigned short int valor9; // Ao menos 16 bits
    cout << valor9 << endl;
    unsigned valor10 {66}; // unsigned int valor10; // Ao menos 16 bits
    cout << valor10 << endl;
    unsigned long valor11 {25554545}; // unsigned long int valor11; // Ao menos 32 bits
    cout << valor11 << endl;
    unsigned long long valor12 {14'600'000'000}; // unsigned long long int valor12; // Ao menos 64 bits
    cout << valor12 << endl;

    /*
    * PONTOS FLUTUANTES
    */
    cout << "<===========================>" << endl;
    cout << "EXEMPLO FLUTUANTES" << endl;
    float valor13 {401.23f}; // 7 digitos decimais => 1,2 x 10^-38 at� 3,4 x 10^38
    cout << valor13 << endl;
    double valor14 {3.14159}; // 15 digitos decimais => 2,2 x 10^-308 at� 1,8 x 10^308
    cout << valor14 << endl;
    long double valor15 {2.7e120}; // 19 digitos decimais => 3,3 x 10^-4932 at� 1,2 x 10^4932
    cout << valor15 << endl;

    /*
    * BOLEANOS
    */
    cout << "<===========================>" << endl;
    cout << "EXEMPLO BOLEANOS" << endl;
    bool valor16 {false};
    cout << valor16 << endl;

    /*
    * ESPECIAIS
    */
    // Pode armazenar o valor maximo teoricamente para qualquer tipo de objeto
    // incluindo arrays
    cout << "<===========================>" << endl;
    cout << "EXEMPLO ESPECIAIS" << endl;
    std::size_t valor17;    
    cout << valor17 << endl; 

    /*
    * OVERFLOW
    */
    cout << "<===========================>" << endl;
    cout << "EXEMPLO OVERFLOW" << endl;
    short valor18 {30000};
    cout << valor18 << endl; 
    short valor19 {1000};
    cout << valor19 << endl; 
    short valor20 {valor18 * valor19};
    cout << valor18 << " * " << valor19 << " = " << valor20 << endl; 

    return 0;
}