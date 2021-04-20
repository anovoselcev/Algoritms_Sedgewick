#include <iostream>
#include <unordered_map>

template<typename T>
struct Node {
    T value;
    Node* root = nullptr;
    Node* next = nullptr;
};

struct check {
    bool done = false;
};


template<typename T>
Node<T>* traverse(Node<T>** graph, Node<T>* node) {
    if (!graph || !node) return nullptr;

    static std::unordered_map<Node<T>*, check> visited = { {nullptr, {true}} };
    visited[node].done = true;
    for (Node<T>* ptr = node; ptr; ptr = ptr->next)
        if (!visited[ptr->root].done) traverse(graph, ptr->root);

}


int main() {
    Node<double>** graph = new Node<double>*[3];
    for (size_t i = 0; i < 3; ++i) graph[i] = new Node<double>[1];
    graph[0][0] = { 0, graph[2] };
    graph[1][0] = { 1, graph[0] };
    graph[2][0] = { 2, graph[1] };
    traverse(graph, graph[0]);
}