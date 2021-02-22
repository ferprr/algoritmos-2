#ifndef grafo
#define grafo

#include <list>
#include <vector>

using namespace std;

class Grafo {

    int nos;
    int custo_minimo;
    int atratividade_agregada;
    int **ciclovia;
    int *atratividade;
    int *partidas_chegadas;
    int **mst;

    public:
        Grafo(int n);
        ~Grafo();
        void inicializa_matriz();
        void imprime_matriz();
        void set_custo(int pi, int pj, int ct);
        void primMST();
        void printMST();
        void set_atratividade(int no, int valor);
};

#endif