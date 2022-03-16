## Tecnologias e ferramentas usadas
- C++
- VSCode

# Parte I: INTRODUÇÃO AO C++
## CAPÍTULO 1: UMA VISÃO RÁPIDA SOBRE O C++ E A BIBLIOTECA PADRÃO
### O básico sobre C++
#### O Hello World obrigatório
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
Esse código, como você pode esperar, imprimi na tela a mensagem "Hello, World!". É um simples programa no qual consegue exibir os seguintes conceitos muito importantes sobre o formato de um programa em C++.
- Comentários
- Diretiva do pré-processador
- A função main()
- Fluxo de I/O
##### Comentários
A primeira linha do programa é um comentario, que nada mais é do que uma mensagem que existe apenas para o programador e é ignorada pelo compilador. Em c++ existe duas maneiras de retratar um comentário. Nos exemplos posteriores, duas barras indicam que o que mais vir na mesma linha será um comentário.

O mesmo comportamento pode ser obtido usando o comentário multi-linha. Comentários multi-linhas começam com ```/*``` e terminam com ```*/```. O seguinte código mostra um comentário multi-linha:
```c++
/* Esse é um comentário multi-linha.
    O compilador irá ignorá-lo.
  */
```
##### Diretivas do pré-processador
##### A função main()
##### Fluxos de I/O

## REFERENCIAS:
- Marc Gregoire. Professional C++, 4th Edition.
