# 🖥️ Simulador de Escalonamento de Processos | CPU Scheduling Simulator

[![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)](https://github.com/seu-usuario/seu-repositorio)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)

---

## 🇧🇷 Português

### 📌 Sobre o Projeto

Este projeto foi desenvolvido como parte da disciplina de **Sistemas Operacionais** do curso de **Engenharia de Computação na UNIFEI**. Ele simula como o kernel de um Sistema Operacional gerencia a fila de processos na CPU através de algoritmos clássicos de escalonamento.

### 💡 Motivação

Durante os estudos de Sistemas Operacionais, percebi que o escalonamento de processos é um dos conceitos mais fundamentais — e também um dos mais difíceis de visualizar na prática. Decidi criar este simulador com dois objetivos:

1. **Fixar o conteúdo:** Implementar os algoritmos do zero é a melhor forma de realmente entender como cada um funciona, seus trade-offs e comportamentos em diferentes cenários.
2. **Criar uma ferramenta de aprendizado:** Vi que era possível transformar a teoria em algo interativo, que facilita a compreensão não só para mim, mas para outros estudantes que enfrentam a mesma dificuldade.

### ⚙️ Algoritmos Implementados

| Algoritmo | Tipo | Descrição |
|-----------|------|-----------|
| **FCFS** (First-Come, First-Served) | Não-preemptivo | Execução por ordem de chegada |
| **SJF** (Shortest Job First) | Não-preemptivo | Prioriza processos com menor tempo de execução |
| **Round Robin (RR)** | Preemptivo | Escalonamento com fatia de tempo (Quantum) configurável |

### 📊 Funcionalidades

- Simulação passo a passo com timeline de execução
- Relatório com métricas: **Tempo de Espera** e **Turnaround** por processo
- Cálculo automático das **médias** de espera e turnaround
- Entrada interativa de processos via terminal

### 🛠️ Como Compilar e Rodar

```bash
# Compilar
g++ -o simulador src/main.cpp src/escalonador.cpp

# Executar
./simulador
```

### 📁 Estrutura do Projeto

```
escalonador-de-processos/
├── src/
│   ├── main.cpp           # Ponto de entrada e menu interativo
│   ├── escalonador.cpp    # Implementação dos algoritmos (FCFS, SJF, RR)
│   └── Processo.hpp       # Struct do processo (id, tempos, etc.)
└── README.md
```

---

## 🇺🇸 English

### 📌 About the Project

This project was developed for the **Operating Systems** course in the **Computer Engineering** program at **UNIFEI**. It simulates how an OS kernel manages the process queue in the CPU using classic scheduling algorithms.

### 💡 Motivation

While studying Operating Systems, I realized that process scheduling is one of the most fundamental concepts — and also one of the hardest to visualize in practice. I decided to build this simulator with two goals:

1. **Solidify my knowledge:** Implementing the algorithms from scratch is the best way to truly understand how each one works, their trade-offs, and behaviors in different scenarios.
2. **Provide a learning tool:** I saw an opportunity to turn theory into something interactive, making it easier to understand — not just for me, but for other students facing the same challenges.

### ⚙️ Implemented Algorithms

| Algorithm | Type | Description |
|-----------|------|-------------|
| **FCFS** (First-Come, First-Served) | Non-preemptive | Executes in arrival order |
| **SJF** (Shortest Job First) | Non-preemptive | Prioritizes the process with the shortest burst time |
| **Round Robin (RR)** | Preemptive | Scheduling using a configurable time slice (Quantum) |

### 📊 Features

- Step-by-step simulation with execution timeline
- Report with metrics: **Waiting Time** and **Turnaround** per process
- Automatic calculation of **average** waiting and turnaround times
- Interactive process input via terminal

### 🛠️ How to Compile and Run

```bash
# Compile
g++ -o simulator src/main.cpp src/escalonador.cpp

# Run
./simulator
```

---

## 🚀 Roadmap (v2.0.0)

- [ ] **GUI:** Interface gráfica com animação em tempo real (SFML/Qt)
- [ ] **Priority Scheduling:** Suporte a prioridades de processos
- [ ] **CSV Support:** Importação de listas de processos via arquivo
- [ ] **Diagrama de Gantt:** Visualização gráfica do escalonamento

---

## 🎓 Autor | Author

**Pedro** — Estudante de Engenharia de Computação na UNIFEI.

---

> *"A melhor forma de aprender é construindo."*
