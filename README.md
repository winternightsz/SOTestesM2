## Alunas: Helena Becker Piazera e Izabela Andreazza.

# Avaliação de Page Faults com C++ e Python

Este repositório contém três scripts utilizados para avaliar o comportamento de page faults durante a execução de operações intensivas de processamento e manipulação de memória. O projeto inclui dois scripts em C++ e um em Python, cobrindo operações de multiplicação de matrizes e alocação de memória.

## Estrutura dos Arquivos

1. **MultiplicacaoMatrizesC.cpp** - Implementação em C++ para a multiplicação de matrizes.
2. **main.py** - Implementação em Python para a multiplicação de matrizes, com propósito igual ao arquivo em C++.
3. **main.cpp** - Script em C++ que realiza operações de alocação e manipulação de memória.

## Compilação e Execução

Cada código pode ser compilado e executado utilizando os comandos listados abaixo. Durante a execução, é possível monitorar os processos para visualizar estatísticas como PID, `min_flt` (page faults leves), `maj_flt` (page faults graves) e `comm` (comando).

### Comandos de Compilação e Execução

- **Python (main.py)**:
  ```bash
  python3 main.py & pid=$!; while kill -0 $pid 2>/dev/null; do ps -o pid,min_flt,maj_flt,comm -p $pid; sleep 0.5; done
  ```

- **C++ (MultiplicacaoMatrizesC.cpp)**:
  ```bash
  g++ -std=c++11 MultiplicacaoMatrizesC.cpp -o MultiplicacaoMatrizesC
  ./MultiplicacaoMatrizesC & pid=$!; while kill -0 $pid 2>/dev/null; do ps -o pid,min_flt,maj_flt,comm -p $pid; sleep 0.5; done
  ```

- **C++ (main.cpp)**:
  ```bash
  g++ -std=c++11 main.cpp -o main -pthread
  ./main & pid=$!; while kill -0 $pid 2>/dev/null; do ps -o pid,min_flt,maj_flt,comm -p $pid; sleep 0.5; done
  ```

## Monitoramento de Processos

Os comandos acima monitoram o processo em execução e exibem as estatísticas de page faults em intervalos de 0.5 segundos. Isso permite uma análise em tempo real do uso de memória e da quantidade de page faults ocorridos durante a execução de cada programa.

## Propósito e Resultados

Esses códigos foram desenvolvidos para analisar como operações intensivas de memória afetam o desempenho do sistema, especialmente em relação a page faults. A análise de `min_flt` e `maj_flt` fornece insights sobre o impacto da alocação de memória e operações intensivas de processamento no gerenciamento de memória do sistema operacional.
