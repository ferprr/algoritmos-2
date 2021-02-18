#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    
    int n, t;
    cin >> n >> t;

    vector<int> pontos_interesse;

    for (int i=0; i<n; i++) {
        int valor_turistico;
        cin >> valor_turistico;
        pontos_interesse.push_back(valor_turistico);
    }

    for (int i=0; i<t; i++) {
        int pi, pj, ct;
        cin >> pi >> pj >> ct;
        cout << pi << " " << pj << " " << ct << endl;
    }

}

