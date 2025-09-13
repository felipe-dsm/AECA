#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include "Analisador.hpp"
#include "Algoritmos.hpp"

/**
 * @brief Função externa de exemplo.
 * @details Esta função simula uma chamada a uma função que não faz parte
 * do projeto original, conforme solicitado nos requisitos.
 * Sua implementação poderia estar em uma biblioteca separada.
 */
void chamadaExterna() {
    std::cout << "\n>>> Executando uma funcao externa ao projeto. <<<\n" << std::endl;
    // Aqui poderia haver lógica complexa, carregamento de configurações, etc.
}

/**
 * @brief Função principal que executa a análise de complexidade.
 */
int main() {
    // Possibilidade de chamada de funções externas, conforme requisito
    chamadaExterna();

    Analisador analisador;

    // Define os tamanhos de entrada (n) para os testes
    std::vector<int> tamanhos_n = {100, 500, 1000, 2000, 5000, 8000, 10000};
    
    // Número de repetições para cada tamanho de 'n' para obter uma média estável
    int num_repeticoes = 5;

    // --- Análise do Insertion Sort ---
    // A função é passada como um objeto std::function
    analisador.executarAnalise("Insertion Sort - O(n^2)", insertionSort, tamanhos_n, num_repeticoes);

    // --- Análise do Merge Sort ---
    analisador.executarAnalise("Merge Sort - O(n.log(n))", mergeSort, tamanhos_n, num_repeticoes);

    /*
     * Exemplo de como adicionar um novo algoritmo (por exemplo, Quick Sort):
     * 1. Adicione a implementação de 'quickSort' em Algoritmos.hpp.
     * 2. Adicione a chamada de análise aqui:
     *
     * analisador.executarAnalise("Quick Sort - O(n.log(n))", quickSort, tamanhos_n, num_repeticoes);
     *
     * Exemplo de como chamar um algoritmo "externo":
     * Se 'algoritmoExterno' estivesse definido em uma biblioteca externa e linkado,
     * poderíamos chamá-lo da seguinte forma:
     *
     * analisador.executarAnalise("Algoritmo Externo", algoritmoExterno, tamanhos_n, num_repeticoes);
     */

    std::cout << "Analise concluida. Copie os dados e utilize uma ferramenta de plotagem para gerar os graficos." << std::endl;

    return 0;
}
