# Desafios de código

## Salário
Escreva um programa que leia o número de um funcionário, seu número de horas trabalhadas, o valor que recebe por hora e calcula o salário desse funcionário. A seguir, mostre o número e o salário do funcionário, com duas casas decimais.

**Entrada**

O arquivo de entrada contém 2 números inteiros e 1 número com duas casas decimais, representando o número, quantidade de horas trabalhadas e o valor que o funcionário recebe por hora trabalhada, respectivamente.

**Saída**

Imprima o número e o salário do funcionário, conforme exemplo fornecido, com um espaço em branco antes e depois da igualdade. No caso do salário, também deve haver um espaço em branco após o $.

| **Exemplos de Entrada** |     **Exemplos de Saída**     |
|-------------------------|-------------------------------|
| 25 100 5.50             |NUMBER = 25; SALARY = U$ 550.00|
| 1 200 20.50             |NUMBER = 1; SALARY = U$ 4100.00|
| 6 145 15.55             |NUMBER = 6; SALARY = U$ 2254.75|

**Resolução**

``` JavaScript
var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let number =  parseInt(lines.shift());
let hours =  parseInt(lines.shift());
let valueHours = parseFloat(lines.shift());

salary = parseFloat(hours * valueHours);


console.log(`NUMBER = ${number}`);
console.log(`SALARY = U$ ${salary.toFixed(2)}`);
```

## Salário com Bônus
Faça um programa que leia o nome de um vendedor, o seu salário fixo e o total de vendas efetuadas por ele no mês (em dinheiro). Sabendo que este vendedor ganha 15% de comissão sobre suas vendas efetuadas, informar o total a receber no final do mês, com duas casas decimais.

**Entrada**

O arquivo de entrada contém um texto (primeiro nome do vendedor) e 2 valores de dupla precisão (double) com duas casas decimais, representando o salário fixo do vendedor e montante total das vendas efetuadas por este vendedor, respectivamente.

**Saída**

Imprima o total que o funcionário deverá receber, conforme exemplo fornecido.

| **Exemplos de Entrada** |**Exemplos de Saída**|
|-------------------------|---------------------|
| JOAO 500.00 1230.30     |  TOTAL = R$ 684.54  |
| PREDO 700.00 0.00       |  TOTAL = R$ 700.00  |
| LUANA 1700.00 1230.50   |  TOTAL = R$ 1884.58 |

**Resolução**

``` JavaScript
var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let firstName = lines.shift();
let salary = parseFloat(lines.shift()); // salario fixo
let sales = parseFloat(lines.shift()); // vendas

bonus = sales * (15/100)
salaryTotal = parseFloat(salary + bonus);

console.log(`TOTAL = R$ ${salaryTotal.toFixed(2)}`)
```
