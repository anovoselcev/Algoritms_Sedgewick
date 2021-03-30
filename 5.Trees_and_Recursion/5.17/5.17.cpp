
#include <iostream>

template<typename T>
struct Node{
    T value;
    Node* next = nullptr;
};

template<typename T>
T max(Node<T>* head) {
    if (!head) return T{};

    T m = max(head->next);
    if (head->value > m) return head->value;
    else return m;
}

int main()
{
    std::cout << "Hello World!\n";
}