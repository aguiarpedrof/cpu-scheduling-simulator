#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include "Processo.hpp"

using namespace std;

// --- FCFS: First-Come, First-Served ---
void executarFCFS(vector<Processo>& processos) {
    sort(processos.begin(), processos.end(), [](const Processo& a, const Processo& b) {
        return a.tempoChegada < b.tempoChegada;
        });

    int tempoAtual = 0;
    cout << "\n--- EXECUTANDO FCFS ---\n";

    for (auto& p : processos) {
        if (tempoAtual < p.tempoChegada) tempoAtual = p.tempoChegada;

        int inicio = tempoAtual;
        tempoAtual += p.tempoExecucao;

        p.tempoConclusao = tempoAtual;
        p.tempoTurnaround = p.tempoConclusao - p.tempoChegada;
        p.tempoEspera = inicio - p.tempoChegada;

        cout << "[Tempo " << inicio << "-" << tempoAtual << "] P" << p.id << " em execução." << endl;
    }
}

// --- ROUND ROBIN (RR) ---
void executarRoundRobin(vector<Processo>& processos, int quantum) {
    queue<int> fila;
    int tempoAtual = 0, concluidos = 0, n = processos.size();
    vector<bool> naFila(n, false);

    cout << "\n--- EXECUTANDO ROUND ROBIN (Quantum: " << quantum << ") ---\n";

    while (concluidos < n) {
        for (int i = 0; i < n; i++) {
            if (processos[i].tempoChegada <= tempoAtual && !naFila[i] && processos[i].tempoRestante > 0) {
                fila.push(i);
                naFila[i] = true;
            }
        }

        if (fila.empty()) { tempoAtual++; continue; }

        int idx = fila.front();
        fila.pop();

        int exec = min(processos[idx].tempoRestante, quantum);
        cout << "[Tempo " << tempoAtual << "-" << tempoAtual + exec << "] P" << processos[idx].id << " em execução." << endl;

        processos[idx].tempoRestante -= exec;
        tempoAtual += exec;

        for (int i = 0; i < n; i++) {
            if (processos[i].tempoChegada <= tempoAtual && !naFila[i] && processos[i].tempoRestante > 0) {
                fila.push(i);
                naFila[i] = true;
            }
        }

        if (processos[idx].tempoRestante > 0) {
            fila.push(idx);
        }
        else {
            concluidos++;
            processos[idx].tempoConclusao = tempoAtual;
            processos[idx].tempoTurnaround = processos[idx].tempoConclusao - processos[idx].tempoChegada;
            processos[idx].tempoEspera = processos[idx].tempoTurnaround - processos[idx].tempoExecucao;
        }
    }
}

// --- SJF: Shortest Job First ---
void executarSJF(vector<Processo>& processos) {
    int n = processos.size(), tempoAtual = 0, concluidos = 0;
    vector<bool> fim(n, false);
    cout << "\n--- EXECUTANDO SJF (Menor Primeiro) ---\n";

    while (concluidos < n) {
        int idx = -1, minBurst = 1e9;
        for (int i = 0; i < n; i++) {
            if (processos[i].tempoChegada <= tempoAtual && !fim[i] && processos[i].tempoExecucao < minBurst) {
                minBurst = processos[i].tempoExecucao;
                idx = i;
            }
        }

        if (idx == -1) {
            tempoAtual++;
        }
        else {
            int inicio = tempoAtual;
            tempoAtual += processos[idx].tempoExecucao;
            processos[idx].tempoConclusao = tempoAtual;
            processos[idx].tempoTurnaround = tempoAtual - processos[idx].tempoChegada;
            processos[idx].tempoEspera = inicio - processos[idx].tempoChegada;
            fim[idx] = true;
            concluidos++;
            cout << "[Tempo " << inicio << "-" << tempoAtual << "] P" << processos[idx].id << " em execução." << endl;
        }
    }
}

void exibirRelatorio(const vector<Processo>& processos) {
    float totalEspera = 0, totalTurnaround = 0;
    cout << "\nID\tChegada\tBurst\tEspera\tTurnaround\n";
    cout << "--------------------------------------------------\n";
    for (const auto& p : processos) {
        cout << p.id << "\t" << p.tempoChegada << "\t" << p.tempoExecucao << "\t" << p.tempoEspera << "\t" << p.tempoTurnaround << endl;
        totalEspera += p.tempoEspera;
        totalTurnaround += p.tempoTurnaround;
    }
    cout << fixed << setprecision(2);
    cout << "\nMedia de Espera: " << totalEspera / processos.size() << "ms";
    cout << "\nMedia de Turnaround: " << totalTurnaround / processos.size() << "ms\n";
}