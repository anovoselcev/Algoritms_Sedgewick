
#include <iostream>

struct Node {
    size_t v;
    Node* next = nullptr;
};

using link = Node*;

int main(int argc, char* argv[]) {
    size_t V = 0;
    std::cin >> V;
    link* adj = new link[V](nullptr);
    size_t a , b, count = 0;
    while (std::cin >> a >> b) {
        for (size_t i = 0; i < V; ++i) {
            link tmp = adj[a];
            std::pair<bool, bool> condition{ false, false };
            while (tmp->next) {
                if (tmp->v == i) {
                    condition.first = true;
                    break;
                }
                tmp = tmp->next;
            }
            tmp = adj[i];
            while (tmp->next) {
                if (tmp->v == b) {
                    condition.second = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (condition.first && condition.second) count++;
        }
    }
}