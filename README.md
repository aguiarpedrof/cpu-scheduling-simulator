# 🖥️ Simulador de Escalonamento de Processos | CPU Scheduling Simulator

[![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)](https://github.com/seu-usuario/seu-repositorio)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 🇧🇷 Português

### Sobre o Projeto
Este projeto foi desenvolvido como parte da disciplina de **Sistemas Operacionais** do curso de **Engenharia de Computação na UNIFEI**. Ele simula como o kernel de um SO gerencia a fila de processos na CPU através de algoritmos clássicos.

### Algoritmos Implementados
* **FCFS (First-Come, First-Served):** Execução por ordem de chegada.
* **SJF (Shortest Job First):** Prioriza processos com menor tempo de execução.
* **Round Robin (RR):** Escalonamento preemptivo com fatia de tempo (Quantum).



### Como Rodar
```bash
g++ -o simulador src/main.cpp src/escalonador.cpp
./simulador
🇺🇸 English
About the Project
This project was developed for the Operating Systems course in the Computer Engineering program at UNIFEI. It simulates how an OS kernel manages the process queue in the CPU using classic algorithms.

Implemented Algorithms
FCFS (First-Come, First-Served): Non-preemptive, executes in arrival order.

SJF (Shortest Job First): Prioritizes the process with the shortest burst time.

Round Robin (RR): Preemptive scheduling using a time slice (Quantum).

How to Run
Bash
g++ -o simulator src/main.cpp src/escalonador.cpp
./simulator
🚀 Roadmap (v2.0.0)
[ ] GUI: Interface gráfica com animação em tempo real (SFML/Qt).

[ ] Priority Scheduling: Adicionar suporte a prioridades de processos.

[ ] CSV Support: Importação de listas de processos via arquivo.

🎓 Author
Pedro - Computer Engineering Student at UNIFEI.