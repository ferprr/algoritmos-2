#include "headers/Grafo.hpp"
#include <iostream>
#include <cstring>
#include <list>

using namespace std;
#define INF 9999999

Grafo::Grafo(int n) {
    this->nos = n;
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
void Grafo::prim() {
    int no_edge = 0;
    int *selected = new int[nos];
    memset(selected, false, sizeof(selected));

    selected[0] = true;
    int x; 
    int y;
    while (no_edge < nos - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < nos; i++) {
            if (selected[i]) {
                for (int j = 0; j < nos; j++) {
                    if (!selected[j] && ciclovia[i][j]) {
                        if (min > ciclovia[i][j]) {
                            min = ciclovia[i][j];
                            x = i;
                            y = j;
                        }
                    }
                    }
            }
        }
        cout << x << " - " << y << " :  " << ciclovia[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
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
    //ciclovia[pj][pi] = ct;

}