#ifndef grafo
#define grafo

#include <list>
#include <vector>

using namespace std;

class Grafo {

    int nos;
    int **ciclovia;
    vector<int> atratividade;

    public:
        Grafo(int n);
        ~Grafo();
        void inicializa_matriz();
        void imprime_matriz();
        void set_custo(int pi, int pj, int ct);
        void primMST();
        void printMST(int parent[]);
        int minKey(int key[], bool mstSet[]);
        void set_atratividade(int valor);
};

#endif