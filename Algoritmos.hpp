#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <vector>
#include <algorithm> // Para std::merge

/*
 * =================================================================================
 * Algoritmos de Ordenação
 * =================================================================================
 */

// Protótipos para que possam ser usados em outras partes do código
void insertionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr);

/**
 * @brief Ordena um vetor de inteiros usando o algoritmo Insertion Sort.
 * @details Complexidade teórica: O(n^2) no caso médio e pior.
 * @param arr Vetor a ser ordenado.
 */
void insertionSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


/**
 * @brief Função auxiliar para o Merge Sort que mescla dois sub-vetores.
 * @param arr O vetor original.
 * @param l Índice inicial do primeiro sub-vetor.
 * @param m Índice do meio.
 * @param r Índice final do segundo sub-vetor.
 */
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Função recursiva principal do Merge Sort.
 * @param arr Vetor a ser ordenado.
 * @param l Índice esquerdo.
 * @param r Índice direito.
 */
void mergeSortRecursive(std::vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSortRecursive(arr, l, m);
    mergeSortRecursive(arr, m + 1, r);
    merge(arr, l, m, r);
}

/**
 * @brief Ordena um vetor de inteiros usando o algoritmo Merge Sort.
 * @details Complexidade teórica: O(n.log(n)) em todos os casos.
 * @param arr Vetor a ser ordenado.
 */
void mergeSort(std::vector<int>& arr) {
    if (!arr.empty()) {
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }
}


// Exemplo de como um algoritmo externo poderia ser declarado.
// A implementação estaria em outro arquivo de objeto ou biblioteca.
extern "C" void algoritmoExterno(std::vector<int>& arr);

#endif // ALGORITMOS_HPP
