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
std::queue<Node<T>*> ReverseRound(Node<T>* root) {
    std::stack<Node<T>*> stack;
    std::queue<Node<T>*> values;
    Node<T>* lnvn = nullptr;
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
                values.push(peekn);
                lnvn = peekn;
            }
        }
    }
    return values;
}


template<typename T>
Node<T>* FindMax(Node<T>* root) {
    if (!root) return nullptr;
    Node<T>* max = root;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        if (q.front()->value > max->value) max = q.front();
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
    }
    return max;
}

template<typename T>
Node<T>* FindParentOf(Node<T>* target, Node<T>* root) {
    if (!root || !target) return nullptr;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        if (q.front()->left == target || q.front()->right == target) return q.front();
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
    }
    return nullptr;
}

template<typename T>
bool DeleteNode(Node<T>* root, T value) {
    auto parent = root;
    bool side = false;
    while (root) {
        if (root->value > value) {
            parent = root;
            root = root->left;
            side = false;
        }
        else if (root->value < value) {
            parent = root;
            root = root->right;
            side = true;
        }
        else {
            if (parent != root) {
                if (!root->left && !root->right) {
                    if (!side) parent->left = nullptr;
                    else parent->right = nullptr;
                    delete root;
                }
                else if (root->left && !root->right) {
                    if (!side) parent->left = root->left;
                    else parent->right = root->left;
                    delete root;
                }
                else if (!root->left && root->right) {
                    if (!side) parent->left = root->right;
                    else parent->right = root->right;
                    delete root;
                }
                else if (root->left && root->right) {
                    auto max = FindMax(root->left);
                    auto par = FindParentOf(max, root);
                    if (par->left == max) par->left = nullptr;
                    if (par->right == max) par->right = nullptr;
                    root->value = max->value;
                    DeleteNode(max, max->value);
                }
            }
            else {
                if (!root->left && !root->right) {
                    delete root;
                }
                else if (root->left && !root->right) {
                    auto tmp = root->left;
                    root->value = tmp->value;
                    root->left = tmp->left;
                    root->right = tmp->right;
                    delete tmp;
                }
                else if (!root->left && root->right) {
                    auto tmp = root->right;
                    root->value = tmp->value;
                    root->left = tmp->left;
                    root->right = tmp->right;
                    delete tmp;
                }
                else if (root->left && root->right) {
                    auto max = FindMax(root->left);
                    root->value = max->value;
                    DeleteNode(max, max->value);
                }
            }
            return true;
        }
    }
    return false;
}

int main(){
    auto tree = CreateTree<int>(5);
    int target;
    std::cin >> target;
    DeleteNode(tree, target);
    std::cout << "Hi" << std::endl;
}
