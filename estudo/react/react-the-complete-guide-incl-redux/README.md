# Estudando React

## Este conteudo é relacionado ao curso React - The Complete Guide (incl Hooks, React Router, Redux)

- [Link para o curso na Udemy](https://www.udemy.com/course/react-the-complete-guide-incl-redux)

## Seções

## Seção 1: Getting Started

## Seção 2: Javascript Refresher

### Understanding "let" and "const"

Com o novo javascript temos novos tipos de declaração de variáveis `let` e `const`, para tentar sobrepor o uso do `var`. Sendo o `let` para variáveis de contexto e `const` para constantes.

```javascript
let name = 'Paulo';
const PI = 3.14159265359;
```

### Arrow Functions

A nova sintaxe para criar novas funções é através das *arrow funtions*. Elas resolvem muitos dos nossos problemas relacionados a contexto quando trabalhamos com uma função (quando usamos o `this`).

```javascript
// sintaxe antiga:
function multiplyByTwo(number) {
  return number * 2;
}

// nova sintaxe com arrow functions:
const multiplyByTwo = (number) => {
  return number * 2;
}
```

Quando temos apenas um argumento podemos omitir os parentes do mesmo:

```javascript
const multiplyByTwo = number => {
  return number * 2;
}
```

Assim como se tivermos somente o retorno como bloco a ser executado, podemos omitir o `return` e os parenteses:

```javascript
const multiplyByTwo = number => number * 2
```

### Exports and Imports
