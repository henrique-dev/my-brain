#include <iostream>
//#define TABLE_SIZE 200
#define ARRAY_SIZE 404
#define getmax(a,b) ((a)>(b)?(a):(b))
#ifndef TABLE_SIZE
#define TABLE_SIZE 100
#endif

int main()
{
    #if TABLE_SIZE>100
    #undef TABLE_SIZE
    #define TABLE_SIZE 301
    #elif TABLE_SIZE<100
    #undef TABLE_SIZE
    #define TABLE_SIZE 51
    #else
    #undef TABLE_SIZE
    #define TABLE_SIZE 501
    #endif

    #if defined ARRAY_SIZE
    #define TABLE_SIZE ARRAY_SIZE
    #elif !defined BUFFER_SIZE
    #define TABLE_SIZE 128
    #else
    #define TABLE_SIZE BUFFER_SIZE
    #endif 

    #ifdef TABLE_SIZE
    int tabela1[TABLE_SIZE];
    std::cout << "O tamanho da tabela sera de : " << TABLE_SIZE << std::endl;
    #undef TABLE_SIZE
    #endif
    #define TABLE_SIZE 300    

    int tabela2[TABLE_SIZE];
    std::cout << "O tamanho da tabela sera de : " << TABLE_SIZE << std::endl;

    int x = 5, y;
    y = getmax(x, 2);

    std::cout << y << std::endl;
    std::cout << getmax(7, x) << std::endl;

    return 0;
}