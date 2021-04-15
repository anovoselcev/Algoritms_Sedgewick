
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
    std::stack<std::pair<bool, Node<T>*>> stack;
    stack.push({false, root});
    while (!stack.empty()) {
        side = stack.top().first;
        root = stack.top().second;
        if(root->value == value) {
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
        parent = root;
        stack.pop();
        if (root->left) stack.push({ false, root->left });
        if (root->right) stack.push({ true, root->right });
    }
    return false;
}
template<typename T>
Node<T>* CreateTourney(const std::vector<T>& items,
    size_t left,
    size_t right) {
    size_t midd = (left + right) / 2;
    auto root = new Node<T>(items[midd]);
    if (left == right) return root;
    root->left = CreateTourney(items, left, midd);
    root->right = CreateTourney(items, midd + 1, right);
    T u = root->left->value, v = root->right->value;
    if (u > v) root->value = u;
    else root->value = v;
    return root;
}

template<typename T>
void DeleteNodes( Node<T>* root, T value) {
    if (!root) return;
    if (DeleteNode(root, value)) DeleteNodes(root, value);
    else return;
}

template<typename T>
void RestructedTourney(Node<T>* root) {
    std::queue<Node<T>*> q;
    q.push(root);
    auto parent = root;
    while (!q.empty()) {
        root = q.front();
        if (root->left && !root->right) {
            if (root->value == root->left->value) {
                auto tmp = root->left;
                root->left = tmp->left;
                root->right = tmp->right;
                delete tmp;
            }
        }
        else if (!root->left && root->right) {
            if (root->value == root->right->value) {
                auto tmp = root->right;
                root->left = tmp->left;
                root->right = tmp->right;
                delete tmp;
            }
        }
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
        q.pop();
    }
}

template<typename T>
void DeleteNodesAndRestructed(Node<T>* root, T value) {
    DeleteNodes(root, value);
    RestructedTourney(root);
}

int main(){
    std::vector<int> items = { 1, 3, 5, 3, 42, 44, -1, 4 };
    auto tree = CreateTourney(items, 0, items.size() - 1);
    DeleteNodesAndRestructed(tree, 3);
    std::cout << std::endl;
}
