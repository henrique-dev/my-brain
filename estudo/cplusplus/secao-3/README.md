# Váriaveis, Tipos e Constantes
## Visão Geral
- [Variaveis](#variaveis)
- [Tipos fundamentais de dados](#tipos-fundamentais-de-dados)
- [Constantes](#constantes)
- [Declarando e inicializando variaveis](#declarando-e-inicializando-variaveis)
## Váriaveis
A utilidade dos programas "Hello World" mostrados no capítulo anterior é bastante questionável. Tivemos que escrever várias linhas de código, compilá-las e depois executar o programa resultante, apenas para obter o resultado de uma simples frase escrita na tela. Certamente teria sido muito mais rápido digitar a sentença de saída nós mesmos.

No entanto, a programação não se limita apenas a imprimir textos simples na tela. Para ir um pouco mais adiante e poder escrever programas que realizam tarefas úteis que realmente nos poupam trabalho, precisamos introduzir o conceito de variáveis.

Uma variável é uma abstração para um endereço de memória, ou seja, usando nomes ao invés de endereços de memória. Uma variável possui um tipo e um valor. Elas devem ser declaradas antes de serem usadas.

Vamos imaginar que eu lhe peça para lembrar o número 5, e então eu peço que você também memorize o número 2 ao mesmo tempo. Você acabou de armazenar dois valores diferentes em sua memória (5 e 2). Agora, se eu pedir para você adicionar 1 ao primeiro número que eu disse, você deve manter os números 6 (que é 5+1) e 2 em sua memória. Então poderíamos, por exemplo, subtrair esses valores e obter 4 como resultado.

Todo o processo descrito acima é um símile do que um computador pode fazer com duas variáveis. O mesmo processo pode ser expresso em C++ com o seguinte conjunto de instruções:
```c++
a = 5;
b = 2;
a = a + 1;
result = a - b;
```
Obviamente, este é um exemplo muito simples, pois usamos apenas dois pequenos valores inteiros, mas considere que seu computador pode armazenar milhões de números como esses ao mesmo tempo e realizar operações matemáticas sofisticadas com eles.

Agora podemos definir variável como uma parte da memória para armazenar um valor.

Cada variável precisa de um nome que a identifique e a distinga das demais. Por exemplo, no código anterior, os nomes das variáveis eram a, b e result, mas poderíamos ter chamado as variáveis de qualquer nome que pudéssemos inventar, desde que fossem identificadores C++ válidos.

### Variaveis globais

Em C++, as variáveis também podem ser declaradas fora de uma função. Tais variáveis são chamadas de variáveis globais.

#### Declarando e nomeando variáveis globais

Por convenção, as variáveis globais são declaradas no topo de um arquivo, abaixo das inclusões, mas acima de qualquer código. Aqui está um exemplo de uma variável global sendo definida:

```c++
#include <iostream>

// Variáveis declaradas fora de uma função são variáveis globais
int g_x {}; // variável global g_x

void doSomething()
{
    // variáveis globais podem ser vistas e usadas em qualquer lugar do arquivo
    g_x = 3;
    std::cout << g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << g_x << '\n';

    // variáveis globais podem ser vistas e usadas em qualquer lugar do arquivo
    g_x = 5;
    std::cout << g_x << '\n';

    return 0;
}
// g_x sai do escopo aqui
```

Por convenção, muitos desenvolvedores prefixam identificadores de variáveis globais com “g” ou “g_” para indicar que são globais.

#### Variáveis globais têm escopo de arquivo e duração estática

As variáveis globais têm escopo de arquivo (também chamado informalmente de escopo global ou escopo de namespace global), o que significa que elas são visíveis desde o ponto de declaração até o final do arquivo em que são declaradas. Uma vez declarada, uma variável global pode ser usada em qualquer lugar do arquivo a partir desse ponto! No exemplo acima, a variável global ```g_x``` é usada em ambas as funções ```doSomething()``` e ```main()```.

Por serem definidas fora de uma função, as variáveis globais são consideradas parte do namespace global (daí o termo “escopo de namespace global”).

As variáveis globais são criadas quando o programa inicia e destruídas quando ele termina. Isso é chamado de duração estática. Variáveis com duração estática às vezes são chamadas de variáveis estáticas.

Ao contrário das variáveis locais, que não são inicializadas por padrão, as variáveis estáticas são inicializadas com zero por padrão.

#### Inicialização de variável global

Variáveis globais não constantes podem ser inicializadas opcionalmente:

```c++
int g_x; // nenhum inicializador explícito (inicializado com zero por padrão)
int g_y {}; // zero inicializado
int g_z { 1 }; // inicializado com valor
```

#### Variáveis globais constantes

Assim como as variáveis locais, as variáveis globais podem ser constantes. Tal como acontece com todas as constantes, as variáveis globais constantes devem ser inicializadas.

```c++
#include <iostream>

const int g_x; // erro: variáveis constantes devem ser inicializadas
constexpr int g_w; // erro: variáveis constexpr devem ser inicializadas
const int g_y { 1 };  // const variável global g_y, inicializada com um valor
constexpr int g_z { 2 }; // variável global constexpr g_z, inicializada com um valor

void doSomething()
{
    // variáveis globais podem ser vistas e usadas em qualquer lugar do arquivo
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';
}

int main()
{
    doSomething();

    // variáveis globais podem ser vistas e usadas em qualquer lugar do arquivo
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';

    return 0;
}
// g_y e g_z saem do escopo aqui
```

### Identificadores
Um identificador válido é uma sequência de uma ou mais letras, dígitos ou caracteres de sublinhado (_). Espaços, sinais de pontuação e símbolos não podem fazer parte de um identificador. Além disso, os identificadores devem sempre começar com uma letra. Eles também podem começar com um caractere sublinhado (_), mas tais identificadores são -na maioria dos casos- considerados reservados para palavras-chave específicas do compilador ou identificadores externos, bem como identificadores contendo dois caracteres sublinhados sucessivos em qualquer lugar. Em nenhum caso eles podem começar com um dígito.

C++ usa várias palavras-chave para identificar operações e descrições de dados; portanto, identificadores criados por um programador não podem corresponder a essas palavras-chave. As palavras-chave reservadas padrão que não podem ser usadas para identificadores criados pelo programador são:
```
alignas, alignof, and, and_eq, asm, auto, bitand, bitor, bool, break, case, catch, char, char16_t, char32_t, 
class, compl, const, constexpr, const_cast, continue, decltype, default, delete, do, double, dynamic_cast, 
else, enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, 
namespace, new, noexcept, not, not_eq, nullptr, operator, or, or_eq, private, protected, public, register, 
reinterpret_cast, return, short, signed, sizeof, static, static_assert, static_cast, struct, switch, template, 
this, thread_local, throw, true, try, typedef, typeid, typename, union, unsigned, using, virtual, void, volatile, 
wchar_t, while, xor, xor_eq
```
Compiladores específicos também podem ter palavras-chave reservadas específicas adicionais.

Muito importante: A linguagem C++ é uma linguagem "case sensitive". Isso significa que um identificador escrito em letras maiúsculas não é equivalente a outro com o mesmo nome, mas escrito em letras minúsculas. Assim, por exemplo, a variável ```RESULTADO``` não é a mesma que a variável ```resultado``` ou a variável ```Resultado```. Estes são três identificadores diferentes que identificam três variáveis diferentes.

## Tipos fundamentais de dados
Os valores das variáveis são armazenados em algum lugar não especificado na memória do computador como zeros e uns. Nosso programa não precisa saber a localização exata onde uma variável está armazenada; ele pode simplesmente se referir a ele por seu nome. O que o programa precisa estar ciente é o tipo de dados armazenados na variável. Armazenar um inteiro simples não é o mesmo que armazenar uma letra ou um grande número de ponto flutuante; mesmo sendo todos representados com zeros e uns, eles não são interpretados da mesma forma e, em muitos casos, não ocupam a mesma quantidade de memória.

Tipos de dados fundamentais são tipos básicos implementados diretamente pela linguagem que representam as unidades básicas de armazenamento suportadas nativamente pela maioria dos sistemas. Eles podem ser classificados principalmente em:

- Tipos caracteres: Eles podem representar um único caractere, como ```'A'``` ou ```'$'```. O tipo mais básico é ```char```, que é um caractere de um byte. Outros tipos também são fornecidos para caracteres mais largos.
- Tipos inteiros numéricos: Eles podem armazenar um valor de número inteiro, como 7 ou 1024. Eles existem em vários tamanhos e podem ser assinados ou não, dependendo se suportam valores negativos ou não.
- Tipos ponto flutuante: Eles podem representar valores reais, como 3,14 ou 0,01, com diferentes níveis de precisão, dependendo de qual dos três tipos de ponto flutuante é usado.
- Tipo booleano: O tipo booleano, conhecido em C++ como ```bool```, só pode representar um de dois estados, *verdadeiro* ou *falso*.

Aqui está um lista de tipos fundamentais em C++:

<table>
    <thead>
        <tr>
            <td>Grupo</td>
            <td>Nome dos tipos</td>
            <td>Notas sobre tamanho/precisão</td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan='4'>Tipos caracteres</td>
            <td>char</td>
            <td>Exatamente um byte de tamanho. Pelo menos 8 bits</td>
        </tr>
        <tr>
            <td>char16_t</td>
            <td>Não menor que char. Pelo menos 16 bits.</td>
        </tr>
        <tr>
            <td>char32_t</td>
            <td>Não menor que char16_t. Pelo menos 32 bits</td>
        </tr>
        <tr>
            <td>wchar_t</td>
            <td>Pode representar o maior conjunto de caracteres suportado</td>
        </tr>
        <tr>
            <td rowspan='5'>Tipos inteiros (<em>signed</em>)</td>
            <td>signed char	</td>
            <td>Same size as char. At least 8 bits</td>
        </tr>
        <tr>
            <td><em>signed</em> short <em>int</em></td>
            <td>Não menor que char. Pelo menos 16 bits</td>
        </tr>
        <tr>
            <td><em>signed</em> int</td>
            <td>Não menor que curto. Pelo menos 16 bits</td>
        </tr>
        <tr>
            <td><em>signed</em> long <em>int</em></td>
            <td>Não menor que int. Pelo menos 32 bits</td>
        </tr>
        <tr>
            <td><em>signed</em> long long <em>int</em></td>
            <td>Não menor que longo. Pelo menos 64 bits</td>
        </tr>
        <tr>
            <td rowspan='5'>Tipos inteiros (<em>unsigned</em>)</td>
            <td>unsigned char</td>
            <td rowspan='5'>(mesmo tamanho que suas contrapartes assinadas)</td>
        </tr>
        <tr>
            <td>unsigned short <em>int</em></td>            
        </tr>
        <tr>
            <td>unsigned <em>int</em></td>
        </tr>
        <tr>
            <td>unsigned long <em>int</em></td>
        </tr>
        <tr>
            <td>unsigned long long <em>int</em></td>
        </tr>
        <tr>
            <td rowspan='3'>Tipos ponto flutuante</td>
            <td>float</td>
            <td></td>
        </tr>
        <tr>
            <td>double</td>
            <td>Precisão não inferior a float</td>
        </tr>
        <tr>
            <td>long double</td>
            <td>Precisão não inferior a double</td>
        </tr>
        <tr>
            <td>Tipo booleano</td>
            <td>bool</td>
            <td></td>
        </tr>
        <tr>
            <td>Tipo vazio</td>    
            <td>void</td>
            <td>nenhum armazenamento</td>
        </tr>
        <tr>
            <td>Tipo nulo</td>    
            <td>decltype(nullptr)</td>
            <td></td>
        </tr>
    </tbody>
</table>

Os nomes de certos tipos inteiros podem ser abreviados sem seus componentes ```signed``` e ```int``` - apenas a parte que não está em itálico é necessária para identificar o tipo, a parte em itálico é opcional. Ou seja, o ```signed short int``` pode ser abreviado como ```signed short int```, ```short int``` ou simplesmente ```short```; todos eles identificam o mesmo tipo fundamental.

Dentro de cada um dos grupos acima, a diferença entre os tipos é apenas seu tamanho (ou seja, quanto eles ocupam na memória): o primeiro tipo em cada grupo é o menor e o último é o maior, com cada tipo sendo pelo menos tão grande como o anterior no mesmo grupo. Fora isso, os tipos em um grupo têm as mesmas propriedades.

Os tamanhos dos tipos acima são expressos em bits; quanto mais bits um tipo tem, mais valores distintos ele pode representar, mas ao mesmo tempo, também consome mais espaço na memória:

Tamanho | Valores representáveis | Notas
--- | ---: | :---
8-bit | 256	| = 28
16-bit | 65 536 | = 216
32-bit | 4 294 967 296 | = 232 (~4 bilhões)
64-bit | 18 446 744 073 709 551 616 | = 264 (~18 bilhões de bilhões)

## Constantes

Constantes referem-se a valores fixos que o programa não pode alterar e são chamados de literais.

As constantes podem ser de qualquer um dos tipos de dados básicos e podem ser divididas em numerais inteiros, numerais de ponto flutuante, caracteres, strings e valores booleanos.

Novamente, as constantes são tratadas como variáveis regulares, exceto que seus valores não podem ser modificados após sua definição.

### Literais inteiros

Um literal inteiro pode ser uma constante decimal, octal ou hexadecimal. Um prefixo especifica a base ou raiz: 0x ou 0X para hexadecimal, 0 para octal e nada para decimal.

Um literal inteiro também pode ter um sufixo que é uma combinação de U e L, para unsigned e long, respectivamente. O sufixo pode ser maiúsculo ou minúsculo e pode estar em qualquer ordem.

Aqui estão alguns exemplos de literais inteiros

```c++
212         // Legal
215u        // Legal
0xFeeL      // Legal
078         // Illegal: 8 is not an octal digit
032UU       // Illegal: cannot repeat a suffix
```

A seguir estão outros exemplos de vários tipos de literais inteiros
```c++
85         // decimal
0213       // octal
0x4b       // hexadecimal
30         // int
30u        // unsigned int
30l        // long
30ul       // unsigned long
```

### Literais de ponto flutuante

Um literal de ponto flutuante tem uma parte inteira, um ponto decimal, uma parte fracionária e uma parte expoente. Você pode representar literais de ponto flutuante na forma decimal ou exponencial.

Ao representar usando a forma decimal, você deve incluir o ponto decimal, o expoente ou ambos e, ao representar usando a forma exponencial, você deve incluir a parte inteira, a parte fracionária ou ambas. O expoente com sinal é introduzido por e ou E.

Aqui estão alguns exemplos de literais de ponto flutuante

```c++
3.14159       // Legal
314159E-5L    // Legal
510E          // Illegal: incomplete exponent
210f          // Illegal: no decimal or exponent
.e55          // Illegal: missing integer or fraction
```

### Literais Booleanos

Existem dois literais booleanos e eles fazem parte das palavras-chave padrão do C++

- Um valor de true representando true.
- Um valor de false representando false.

Você não deve considerar o valor de true igual a 1 e valor de false igual a 0.

### Literais de caracteres

Os literais de caracteres são colocados entre aspas simples. Se o literal começar com L (somente maiúsculo), é um literal de caractere largo (por exemplo, L'x') e deve ser armazenado no tipo wchar_t da variável . Caso contrário, é um literal de caractere estreito (por exemplo, 'x') e pode ser armazenado em uma variável simples do tipo char.

Um literal de caractere pode ser um caractere simples (por exemplo, 'x'), uma sequência de escape (por exemplo, '\t') ou um caractere universal (por exemplo, '\u02C0').

Existem certos caracteres em C++ quando são precedidos por uma barra invertida, eles terão um significado especial e são usados para representar como nova linha (\n) ou tabulação (\t). Aqui, você tem uma lista de alguns desses códigos de sequência de escape

Escape sequence | Meaning
--- | ---
\\ | \ caractere
\' |	caractere '
\" |	caractere "
\? |	caractere ?
\a |	Alerta ou campainha
\b |	Backspace
\f |	Form feed
\n |	Nova linha
\r |	Carriage return
\t |	Horizontal tab
\v |	Vertical tab
\ooo |	Octal number of one to three digits
\xhh . . . |	Hexadecimal number of one or more digits

### Definindo Constantes

Existem duas maneiras simples em C++ para definir constantes

- Usando a diretiva de pré-processador #define
- Usando a palavra-chave const
```c++
#define identifier value
```
```c++
const type variable = value;
```

## Declarando e inicializando variaveis

A sintaxe para declaração de um varaivel em c++ é bem simples. Primeiro deve se dizer o tipo de variavel que queremos e depois o nome da varialve que queremos, e no final colocamos e ponto e virgula.

```c++
int age; // não inicializada
int age = 21; // estilo c de inicialização
int age (21); // inicialização com contrutor
int age {21}; // estilo c++ de inicialização
```