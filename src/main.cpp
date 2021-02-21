#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include "headers/Grafo.hpp"

using namespace std;

int main() {
    
    int n, t;
    cin >> n >> t;
    cout << n << t << endl;

    Grafo bellevile(n);

    for (int i=0; i<n; i++) {
        int atratividade;
        cin >> atratividade;
        bellevile.set_atratividade(atratividade);
        //cout << atratividade << endl;
    }

    bellevile.inicializa_matriz();
    bellevile.imprime_matriz();

    for (int i=0; i<t; i++) {
        int pi, pj;
        long ct;
        cin >> pi >> pj >> ct;
        bellevile.set_custo(pi, pj, ct);
    }

    bellevile.primMST();
}
