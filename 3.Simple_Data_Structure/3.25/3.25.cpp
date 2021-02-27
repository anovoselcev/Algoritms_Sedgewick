#include <iostream>
#include <string>

template<typename Item>
class CycleList {

    struct Node {
        Item value{};
        Node* next = nullptr;
    };

public:
    CycleList() {
        _head.next = _head;
    }

    CycleList(const std::initializer_list<Item>& list) {
        for (const auto& x : list)
            append(x);
    }

    CycleList(const std::initializer_list<Item>&& list) {
        for (auto&& x : list)
            append(x);
    }

    size_t size() const noexcept { return _size; }

    Node* next(size_t idx = 0) const noexcept {
        Node* node = _head;
        for (size_t i = 0; i < idx; ++i)
            node = node->next;
        return node->next;
    }

    void append(const Item& value) {
        if (_size != 0) {
            Node* nd = new Node{ value, _head };
            Node* current = _head;
            while (current->next != _head)
                current = current->next;
            current->next = nd;
        }
        else {
            _head = new Node{ value, nullptr };
            _head->next = _head;
        }
        _size++;

    }
    void append(Item&& value) {
        if (_size != 0) {
            Node* nd = new Node{ value, _head };
            Node* current = _head;
            while (current->next != _head)
                current = current->next;
            current->next = nd;
        }
        else {
            _head = new Node{ value, nullptr };
            _head.next = _head;
        }
        _size++;

    }

    Node* find(const Item& target) {
        Node* node = _head;
        for (size_t i = 0; i < _size; ++i)
            if (node->value == target) return node;
            else node = node->next;
        return nullptr;
    }

    Node* find(Item&& target) {
        Node* node = _head;
        for (size_t i = 0; i < _size; ++i)
            if (node->value == target) return node;
            else node = node->next;
        return nullptr;
    }

    std::pair<size_t, bool> find(Node* target) {
        Node* node = _head;
        for (size_t i = 0; i < _size; ++i)
            if (node == target) return { i, true };
            else node = node->next;
        return { 0, false };
    }

    Node* insert(const Item& value, Node* target) {
        if (!target) return nullptr;
        Node* current = _head;
        for (size_t i = 0; i < _size; ++i) {
            if (current == target) {
                Node* node = new Node{ value, current->next };
                current->next = node;
                _size++;
                return node;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node* insert(CycleList<Item>&& value,
                 Node* target_from,
                 Node* target_to) {
        if (!target_from || !target_to || value._size == 0) return nullptr;
        Node* current = _head;
        for (size_t i = 0; i < _size; ++i) {
            if (current == target_to) {
                Node* tmp_to = current->next;
                Node* tmp_from = target_from->next;

                while (tmp_from->next != target_from)
                    tmp_from = tmp_from->next;
                target_to->next = target_from;
                tmp_from->next = tmp_to;


                _size += value.size();
                value._head = nullptr;
                value._size = 0;
                return current->next;;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node* insert(CycleList<Item>&& value, Node* target) {
        if (!target || value._size() == 0) return nullptr;
        Node* current = _head;
        for (size_t i = 0; i < _size; ++i) {
            if (current == target) {
                Node* tmp = current->next;
                current->next = value.next();
                value.next(value._size() - 1) = tmp;
                _size += value.size();
                value._head = nullptr;
                value._size = 0;
                return current->next;;
            }
        }
        return nullptr;
    }

    size_t getDistance(Node* lhs, Node* rhs) const noexcept {
        if (!lhs || !rhs) return 0;
        size_t dist = 0;
        bool scope = false;
        Node* current = _head;
        for (size_t i = 0; i < _size; ++i) {
            if (scope) dist++;
            if (current == lhs || current == rhs)
                scope = !scope;
            current = current->next;

        }
        return dist < (_size - dist) ? dist : (_size - dist);
    }

    ~CycleList() {

        for (size_t i = 0; i < _size; ++i) {
            Node* ptr = _head;
            _head = _head->next;
            delete ptr;
        }
    }

    Item& operator[](size_t idx) {
        if (idx > _size) throw std::out_of_range(std::to_string(idx) + " wrong index");
        Node* current = _head;
        for (size_t i = 0; i < idx; ++i)
            current = current->next;
        return current->value;
    }

private:

    Node* _head = nullptr;
    size_t _size = 0;
};

int main() {
    CycleList<int> first{ 1, 5, 6, 8, 9, 2, 12 };
    CycleList<int> second{ 5, 7, 1, 76, 123, 14, 65, 34 };
    auto rhs = first.find(8);
    auto lhs = second.find(76);
    first.insert(std::move(second), lhs, rhs);
    for (size_t i = 0; i < first.size(); ++i)
        std::cout << i << "  = " << first[i] << std::endl;
    std::cout << first.size() << std::endl;
    std::cout << second.size() << std::endl;

    return 0;
}