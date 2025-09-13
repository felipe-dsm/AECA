#ifndef ANALISADOR_HPP
#define ANALISADOR_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <functional> // Para std::function
#include <string>
#include <numeric>   // Para std::accumulate
#include <algorithm> // Para std::generate

/**
 * @class Analisador
 * @brief Classe para conduzir a análise empírica de algoritmos.
 */
class Analisador {
public:
    /**
     * @brief Executa a análise empírica de um algoritmo.
     * @param nomeAlgoritmo Nome do algoritmo para exibição.
     * @param algoritmo A função do algoritmo a ser testada.
     * @param tamanhos Vetor com os diferentes tamanhos de entrada (n).
     * @param repeticoes Número de vezes que cada teste será repetido para tirar a média.
     */
    void executarAnalise(
        const std::string& nomeAlgoritmo,
        const std::function<void(std::vector<int>&)>& algoritmo,
        const std::vector<int>& tamanhos,
        int repeticoes) {

        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "Analisando Algoritmo: " << nomeAlgoritmo << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "Tamanho (n)\tTempo Medio (ms)" << std::endl;

        // Gerador de números aleatórios
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 10000);

        for (int n : tamanhos) {
            std::vector<double> tempos;
            tempos.reserve(repeticoes);

            for (int i = 0; i < repeticoes; ++i) {
                // Gerar vetor de entrada aleatório para cada repetição
                std::vector<int> dados(n);
                std::generate(dados.begin(), dados.end(), [&]() { return distrib(gen); });

                // Medir o tempo
                auto start = std::chrono::high_resolution_clock::now();
                algoritmo(dados);
                auto end = std::chrono::high_resolution_clock::now();

                // Armazenar o tempo em milissegundos
                std::chrono::duration<double, std::milli> tempo_ms = end - start;
                tempos.push_back(tempo_ms.count());
            }

            // Calcular a média dos tempos
            double tempoMedio = std::accumulate(tempos.begin(), tempos.end(), 0.0) / repeticoes;
            
            std::cout << n << "\t\t" << std::fixed << tempoMedio << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // ANALISADOR_HPP
