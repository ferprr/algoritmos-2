#include "headers/Grafo.hpp"
#include <iostream>
#include <cstring>
#include <list>
#include <bits/stdc++.h> 

using namespace std;
#define INF 9999999

Grafo::Grafo(int n) {
    this->nos = n;
    this->custo_minimo = 0;
    this->atratividade_agregada = 0;
    this->partidas_chegadas = new int[nos];
    this->atratividade = new int[nos];

    //inicializando vetor de atratividade de cada ponto
    for (int i=0; i<nos; i++) {
        atratividade[i] = 0;
    }
    // for (int i=0; i<nos; i++) {
    //     cout << atratividade[i] << " ";
    // }
    //inicializando vetor de partidas/chegadas em cada ponto
    for (int i = 0; i < nos; i++) {
        partidas_chegadas[i] = 0;
    }
    // for (int i = 0; i < nos; i++) {
    //     cout << partidas_chegadas[i] << " ";
    // }

    inicializa_matriz();
}
Grafo::~Grafo(){
    delete this;
}
void Grafo::inicializa_matriz() {
    ciclovia = (int **)malloc(nos * sizeof(int));
    for (int i=0; i<nos; i++) {
        ciclovia[i] = (int *)malloc(nos*sizeof(int));
    }
    for (int i=0; i<nos; i++) {
        for (int j=0; j<nos; j++) {
            ciclovia[i][j] = 0;
        }
    }

}
void Grafo::imprime_matriz(){
    for (int i=0; i<nos; i++) {
        for (int j=0; j<nos; j++) {
            cout << ciclovia[i][j] << " ";
        }
        cout << endl;
    }
}
void Grafo::set_custo(int pi, int pj, int ct) {
    ciclovia[pi][pj] = ct;
    ciclovia[pj][pi] = ct;

}
void Grafo::set_atratividade(int no, int valor) {
    atratividade[no] = valor;
}
void Grafo::primMST() {
    int *parent = new int[nos];
    int *key = new int[nos];
    bool *mstSet = new bool[nos];  

    for (int i = 0; i < nos; i++) {
        key[i] = INT_MAX, mstSet[i] = false;  
    }  

    key[0] = 0;  
    parent[0] = -1; 

    for (int count = 0; count < nos - 1; count++) {
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  

        for (int v = 0; v < nos; v++) {
            if (ciclovia[u][v] && mstSet[v] == false && ciclovia[u][v] < key[v]) {
                parent[v] = u, key[v] = ciclovia[u][v];
            } 
        }
    }

    printMST(parent);
}
int Grafo::minKey(int key[], bool mstSet[]) {   
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < nos; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}
void Grafo::printMST(int parent[]) {  

    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < nos; i++) {
        cout<<parent[i]<<" - "<<i<<" \t"<<ciclovia[i][parent[i]]<<" \n";  
        custo_minimo += ciclovia[i][parent[i]];
        atratividade_agregada += atratividade[i] + atratividade[parent[i]];

        partidas_chegadas[parent[i]]++;
        partidas_chegadas[i]++;
    }

    cout << "custo: " << custo_minimo << endl;
    cout << "atratividade: " << atratividade_agregada << endl;

    for (int i = 0; i < nos; i++) {
        cout << partidas_chegadas[i] << " ";
    }
}  