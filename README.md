# Seleção Direta em Lista Encadeada (Linguagem C)


## Descrição do Projeto

Este projeto implementa o algoritmo de ordenação **Selection Sort (Seleção Direta)** aplicado a uma **lista encadeada simples**.

A ideia central do algoritmo é dividir a lista em duas partes:

- Parte **ordenada**
- Parte **não ordenada**

A cada iteração:
1. Busca-se o menor elemento da parte não ordenada
2. Esse elemento é colocado na posição correta (início da parte não ordenada)

Neste projeto, a ordenação é feita por **troca de valores (`data`) entre os nós**.


## Complexidade do Algoritmo

### 🟢 Melhor Caso:
$T(n)=\frac{n(n-1)}{2}\rightarrow \Omega(n^2)$

### 🟡 Caso Médio:
$T(n)=\frac{n(n-1)}{2}\rightarrow \Theta(n^2)$

### 🔴 Pior Caso:
$T(n)=\frac{n(n-1)}{2}\rightarrow O(n^2)$

---

> Para os 3 casos, a complexidade é a mesma devido ao fato do algoritmo precisar percorrer todos os elementos de forma quadrática, sem nenhuma otimização dependente do caso.


## Tecnologias Utilizadas

- Linguagem: **C**
- Paradigma: **Estruturas de Dados**
- Tipo de estrutura: **Lista Encadeada Simples**
- Bibliotecas utilizadas:
  - `stdio.h`
  - `stdlib.h`
  - `time.h`


## Estrutura do Projeto

O código está organizado em:

- Definição da estrutura `Node`
- Funções auxiliares:
  - `createNode` → criação de nós
  - `insertBack` → inserção no final
  - `insertFront` → inserção no início
  - `removeNode` → remoção de elementos
  - `printList` → exibição da lista
  - `listSize` → cálculo do tamanho
- Algoritmo de ordenação:
  - `selectionSortLinkedList`
- Função principal:
  - Testes com diferentes cenários


## Como Compilar e Executar

No terminal:

```bash
gcc SelectionSort.c -o programa
```

## Integrantes

- Alexandre Lopes Barreira Neto
- Higor Santos Souza
- João Gabriel Santos e Silva
- João Victor Bertoldo Mesquita
- Kaeliton de França Cardoso
- Luiz Guilherme Prado Morais
- Victor Hugo Resende Marinho
- Yago Pereira Martins