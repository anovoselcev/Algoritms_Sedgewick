
#include <iostream>

int main(){
    size_t V;
    std::cin >> V;
    bool** adj = new bool* [V];
    for (size_t i = 0; i < V; ++i) {
        adj[i] = new bool[V](false);
        adj[i][i] = true;
    }
    size_t a, b, count = 0;
    while (std::cin >> a >> b) {
        for (size_t i = 0; i < V; ++i)
            if (adj[a][i] && adj[i][b]) count++;
    }
}
