
#include <iostream>
#include <stack>
#include <queue>
#include <random>

template<typename T>
struct Node {
    T value;
    Node* left = nullptr,
        * right = nullptr;

    Node(T val) { value = val; }
};


template<typename T>
Node<T>* CreateTree(size_t N) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> d{ -100,200 };
    Node<T>* root = new Node<T>(d(gen));
    for (size_t i = 0; i < N; ++i) {
        Node<T>* tmp = root;
        T value = d(gen);
        bool side = false;
        while (tmp) {
            if (tmp->value > value) {
                side = false;
                if (tmp->left) tmp = tmp->left;
                else break;
            }
            else if (tmp->value < value) {
                side = true;
                if (tmp->right) tmp = tmp->right;
                else break;
            }
            else
                tmp = nullptr;
        }
        if (tmp) {
            if (!side) tmp->left = new Node<T>{ value };
            else tmp->right = new Node<T>{ value };
        }
    }
    return root;
}

template<typename T>
size_t CountLeaf(Node<T>* root) {
    size_t count = 0;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
        if (!root->left && !root->right) count++;
        q.pop();
    }
    return count;
}

int main(){
    std::cout << CountLeaf(CreateTree<int>(100)) << std::endl;
}
