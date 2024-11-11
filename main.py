from threading import Thread

def multiplicar_linhas(matriz_a, matriz_b, resultado, linha):
    for j in range(len(matriz_b[0])):
        resultado[linha][j] = sum(matriz_a[linha][k] * matriz_b[k][j] for k in range(len(matriz_b)))

def multiplicar_matrizes(matriz_a, matriz_b):
    threads = []
    resultado = [[0] * len(matriz_b[0]) for _ in range(len(matriz_a))]
    for i in range(len(matriz_a)):
        thread = Thread(target=multiplicar_linhas, args=(matriz_a, matriz_b, resultado, i))
        threads.append(thread)
        thread.start()
    for thread in threads:
        thread.join()
    return resultado

if __name__ == "__main__":
    tamanho = 1000
    matriz_a = [[1] * tamanho for _ in range(tamanho)]
    matriz_b = [[1] * tamanho for _ in range(tamanho)]
    
    resultado = multiplicar_matrizes(matriz_a, matriz_b)
    print("multiplicacao de matrizes concluida")
