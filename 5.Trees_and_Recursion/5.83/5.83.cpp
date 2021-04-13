
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
Node<T>* CreateTree() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> d{ -100,200 };
    Node<T>* root = new Node<T>(d(gen));
    for (size_t i = 0; i < 3; ++i) {
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
void ReverseRound(Node<T>* root) {
    std::stack<Node<T>*> stack;
    std::queue<T> values;
    Node<T>* lnvn  = nullptr;
    Node<T>* peekn = nullptr;
    while (!stack.empty() || root) {
        if (root) {
            stack.push(root);
            root = root->left;
        }
        else {
            peekn = stack.top();
            if (peekn->right && lnvn != peekn->right) {
                root = peekn->right;
            }
            else {
                stack.pop();
                values.push(peekn->value);
                lnvn = peekn;
            }
        }
    }
    while (!values.empty()) {
        auto tmp = values.front();
        values.pop();
        std::cout << tmp << std::endl;
    }
}

int main(){
    ReverseRound(CreateTree<int>());
}