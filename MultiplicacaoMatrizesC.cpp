#include <iostream>
#include <vector>
#include <thread>

void multiplicar_linhas(const std::vector<std::vector<int>>& matriz_a,
    const std::vector<std::vector<int>>& matriz_b,
    std::vector<std::vector<int>>& resultado, int linha) {
    int n = matriz_b[0].size();
    for (int j = 0; j < n; j++) {
        resultado[linha][j] = 0;
        for (int k = 0; k < matriz_b.size(); k++) {
            resultado[linha][j] += matriz_a[linha][k] * matriz_b[k][j];
        }
    }
}

int main() {
    
    int tamanho = 1000;
    std::vector<std::vector<int>> matriz_a(tamanho, std::vector<int>(tamanho, 1));
    std::vector<std::vector<int>> matriz_b(tamanho, std::vector<int>(tamanho, 1));
    std::vector<std::vector<int>> resultado(tamanho, std::vector<int>(tamanho, 0));
   
    std::vector<std::thread> threads;
    for (int i = 0; i < tamanho; i++) {
        threads.push_back(std::thread(multiplicar_linhas, std::ref(matriz_a), std::ref(matriz_b), std::ref(resultado), i));
    }

    for (auto& th : threads) th.join();

    std::cout << "multiplicacao de matrizes concluida" << std::endl;
    return 0;
}
