
#include <iostream>

int main(int argc, char* argv[]){

    size_t V;
    std::cin >> V;
    bool** adj = new bool* [V];
    for (size_t i = 0; i < V; ++i) {
        adj[i] = new bool[V];
        std::memset(&adj[i], false, V);
        adj[i][i] = 1;
    }
    size_t a = 0, b = 0;
    while (std::cin >> a >> b) {
        adj[a][b] = true;
        adj[b][a] = true;
    }
}

