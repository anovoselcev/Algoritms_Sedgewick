
#include <iostream>

struct Node {
    size_t v;
    Node* next = nullptr;
};

using link = Node*;

int main(int argc, char* argv[]){
    size_t V = 0;
    std::cin >> V;
    link* adj = new link[V](nullptr);
    size_t a = 0, b = 0;
    while (std::cin >> a >> b) {
        adj[a] = new Node{ b, adj[a] };
        adj[b] = new Node{ a, adj[b] };
    }
}
