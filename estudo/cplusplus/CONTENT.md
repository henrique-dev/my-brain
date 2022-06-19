## Tecnologias e ferramentas usadas
- C++
- VSCode

# Parte I: INTRODUÇÃO AO C++
# CAPÍTULO 1: UMA VISÃO RÁPIDA SOBRE O C++ E A BIBLIOTECA PADRÃO
## O básico sobre C++
### O Hello World obrigatório
Em toda sua glória, o seguinte código é o programa mais simples em C++ que vamos encontrar:
```c++
// helloworld.cpp
#include <iostream>

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
```
Esse código, como você pode esperar, imprimi na tela a mensagem "Hello, World!". É um simples programa no qual consegue exibir os seguintes conceitos muito importantes sobre o formato de um programa em C++:
- Comentários
- Diretiva do pré-processador
- A função main()
- Fluxo de I/O
***
#### Comentários
***
A primeira linha do programa é um comentario, que nada mais é do que uma mensagem que existe apenas para o programador e é ignorada pelo compilador. Em c++ existe duas maneiras de retratar um comentário. Nos exemplos posteriores, duas barras indicam que o que mais vir na mesma linha será um comentário.

O mesmo comportamento pode ser obtido usando o comentário multi-linha. Comentários multi-linhas começam com `/*` e terminam com `*/`. O seguinte código mostra um comentário multi-linha:
```c++
/* Esse é um comentário multi-linha.
    O compilador irá ignorá-lo.
  */
```
Os comentários são explicados com mais detalhes no capitulo 3.
#### Diretivas do pré-processador

#### A função main()
#### Fluxos de I/O
### Namespaces
### Literals
### Variáveis
### Operadores
### Tipos
#### Tipos enumerados
#### Estruturas
### Declarações condicionais
#### Declaração if/else
#### Declaração switch
#### O operador condicional
### Operadores de avaliação lógica
### Funções
#### Function Return Type Deduction
#### Current Function's Name
### Arrays no estilo C
### std::array
### std::vector
### Structured Bindings
### Laços de repetição
#### Laço while
#### Laço do/while
#### Laço for
#### Laço Range-Based For
### Initializer Lists
### Those are the basics
## Mergulhando no C++
### Strings em C++
### Ponteiros e memória dinâmica
#### The stack and the heap
#### Trabalhando com ponteiros
#### Arrays dinamicamente alocados
#### Constantes de ponteiro nulo
#### Ponteiros inteligentes
### Os usos de const
#### Constantes
#### Para proteger parametros
### Referencias
#### Passagem por referencia
#### Passagem por referencia const
### Exceções
### Inferencia de tipo
#### A palavra chave auto
#### A palavra chave decltype
## C++ como uma linguagem orientada a objetos
### Definindo classes
### Usando classes
## Inicialização uniforme
### Inicialização direta de lista x inicialização de lista por cópia
## A biblioteca padrão
## Seu primeiro programa C++
### Um sistema de registro de empregado
### A classe Employee
#### Employee.h
#### Employee.cpp
#### EmployeeTest.cpp
### A class Database
#### Database.h
#### Database.cpp
#### DatabaseTest.cpp
### A interface do usuário
### Examinando o programa

## REFERENCIAS:
- Marc Gregoire. Professional C++, 4th Edition.
