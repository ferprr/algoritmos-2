#ifndef grafo
#define grafo

#include <list>

using namespace std;

class Grafo {

    int nos;
    int **ciclovia;

    public:
        Grafo(int n);
        ~Grafo();
        void inicializa_matriz();
        void prim();
        void imprime_matriz();
        void set_custo(int pi, int pj, int ct);
};

#endif