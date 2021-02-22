#include "headers/Grafo.hpp"
#include <iostream>
#include <cstring>
#include <list>
#include <bits/stdc++.h> 

using namespace std;

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
    //inicializando vetor de partidas/chegadas em cada ponto
    for (int i=0; i<nos; i++) {
        partidas_chegadas[i] = 0;
    }

    inicializa_matriz();
}
Grafo::~Grafo(){
    delete this;
}
void Grafo::inicializa_matriz() {

    //incializando matriz que representa trechos de bellevile
    ciclovia = (int **)malloc(nos * sizeof(int));
    for (int i=0; i<nos; i++) {
        ciclovia[i] = (int *)malloc(nos*sizeof(int));
    }
    for (int i=0; i<nos; i++) {
        for (int j=0; j<nos; j++) {
            ciclovia[i][j] = -1;
        }
    }

    //inicializando matriz que representa trechos selecionados pelo algoritmo mst
    mst = (int **)malloc(nos * sizeof(int));
    for (int i=0; i<nos; i++) {
        mst[i] = (int *)malloc(nos*sizeof(int));
    }
    for(int i=0; i<nos; i++){
        for (int j=0; j<nos; j++){
            mst[i][j] = -1;
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
    int arestas = 0; 
    bool selecionados[nos];

    for(int i=0; i<nos; i++){ 
          selecionados[i] = false;
    }  

    selecionados[0] = true;
    int linha, coluna;

    while (arestas < nos - 1) {
        int min = 999999999;
        int atratividade_temp = 0, atratividade_max = 0;
        linha = 0;
        coluna = 0;

        for (int i=0; i<nos; i++) {   //percorrendo a matriz para selecionar a aresta ideal para se ligar ao vertice atual.
            if (selecionados[i]) {        //vertice atual se encontra dentro do vetor de selecionados, o cutset, e portanto pode-se buscar a aresta ideal para se ligar a ele na MST.
                for (int j=0; j<nos; j++) {              
                    atratividade_temp = atratividade[i] + atratividade[j];    
                    if (!selecionados[j] && ciclovia[i][j] >= 0) {             //checando se vertice ainda nao pertence ao cutset e existe aresta ligando o ponto i ao j.
                        if (min > ciclovia[i][j] || (atratividade_max < atratividade_temp && min == ciclovia[i][j])){  //caso aresta atual tenha custo menor ou igual,porem atratividade maior do que as que se sabem ate agora, ela passa a ser a aresta candidata a entrar para MST.
                            min = ciclovia[i][j];       
                            atratividade_max = atratividade_temp;
                            linha = i;
                            coluna = j;
                        }
                     }
                }
            }
        }
        partidas_chegadas[linha]++;    
        partidas_chegadas[coluna]++;
        mst[linha][coluna] = ciclovia[linha][coluna];    //matriz da mst recebe a aresta adequada com o custo, vinda da matriz incial
        custo_minimo += ciclovia[linha][coluna];           
        selecionados[coluna] = true;                                                
        arestas++;      //incrementa-se o numero de arestas pertencentes ao cutset.
    }
}
void Grafo::printMST() {  

    //cálculo da atratividade agregada multiplicando o valor turistico de cada ponto pela quantidade de vezes em que um caminho incide/sai dele na MST.
    for (int i=0; i<nos; i++){                            
        this->atratividade_agregada += atratividade[i] * partidas_chegadas[i];
    } 

    cout << custo_minimo << " " << atratividade_agregada << endl;

    for (int i=0; i<nos; i++){
        cout << partidas_chegadas[i] << " ";
    }

    cout << endl;

    //impressao dos caminhos resultantes apos gerada a MST.
    for(int i=0; i<nos; i++){        
        for (int j=0; j<nos; j++){
            if (mst[i][j] >= 0){
                cout << i << " " << j << " " << mst[i][j] << endl;
                mst[j][i] = -1;    //marcando como -1 a posicao [j][i] apos impresso a posicao [i][j] para evitar duplicatas.
            }
        }
    }
}