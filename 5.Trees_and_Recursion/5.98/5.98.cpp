#include <iostream>
#include <unordered_map>
#include <stack>

template<typename T>
struct Node{
    T value;
    Node* root = nullptr;
    Node* next = nullptr;
};

struct check {
    bool done = false;
};


template<typename T>
Node<T>* traverse(Node<T>** graph) {
    if (!graph) return nullptr;
    std::stack<Node<T>*> stack;
    std::unordered_map<Node<T>*, check> visited = { {nullptr, {true}} };
    stack.push(graph[0]);
    while (!stack.empty()) {
        auto tmp = stack.top();
        if (visited[tmp].done) {
            stack.pop();
            continue;
        }

        stack.pop();
        visited[tmp].done = true;

        while (tmp->next) {
            if(!visited[tmp->root].done) stack.push(tmp->root);
            tmp = tmp->next;
        }

    }

}


int main(){
    Node<double>** graph = new Node<double>*[3];
    graph[0] = new Node<double>[2];
    graph[1] = new Node<double>[2];
    graph[2] = new Node<double>[2];
    graph[0][0].next = graph[2];
    graph[0][1].next = graph[1];
    traverse(graph);
    std::cout << "Hello World!\n";
}
