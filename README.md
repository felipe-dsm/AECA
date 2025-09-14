# Análise Empírica de Complexidade de Algoritmos (AECA)

![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue.svg)
![Plataforma](https://img.shields.io/badge/Plataforma-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)

Este repositório contém o código-fonte do programa utilizado como base para a realização do trabalho da 1ª unidade da disciplina de Estrutura de Dados Básicas II, do curso de Bacharelado em Tecnologia da Informação (BTI) na Universidade Federal do Rio Grande do Norte (UFRN).

## Sobre o Projeto

O objetivo deste projeto é implementar um programa em C++ capaz de avaliar empiricamente o tempo de execução de algoritmos de ordenação.

Os algoritmos analisados foram:
* **Insertion Sort** - Complexidade teórica: $O(n^2)$
* **Merge Sort** - Complexidade teórica: $O(n \log n)$

## Estrutura do Projeto

O código foi desenvolvido de forma modular para facilitar a manutenção e a inclusão de novos algoritmos.

* `main.cpp`: Orquestra a execução da análise, define os tamanhos de entrada e chama o analisador para cada algoritmo.
* `Analisador.hpp`: Contém a classe `Analisador`, responsável por executar os algoritmos, medir o tempo de execução médio com alta precisão usando a biblioteca `<chrono>` e imprimir os resultados.
* `Algoritmos.hpp`: Contém as implementações dos algoritmos de ordenação (Insertion Sort e Merge Sort).

## Como Compilar e Executar

### Pré-requisitos
* Um compilador C++ moderno (g++ recomendado).

### Compilação e Execução
Abra um terminal no diretório do projeto e execute os seguintes comandos:

```bash
# Compile o programa com otimizações
g++ main.cpp -o trabalho_analise -std=c++17 -O2

# Execute o programa
./trabalho_analise
