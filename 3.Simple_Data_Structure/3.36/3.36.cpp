#include <iostream>

template <typename Item>
class List {
    struct Node {
        Item value{};
        Node* next = nullptr;
        Node* prev = nullptr;
    };

public:

    List() = default;

    List(const std::initializer_list<Item>& init) {
        for (const auto& value : init)
            append(value);
    }

    size_t size() const noexcept { return _size; }

    Item& operator[](size_t idx) {
        if (idx < _size) {
            Node* tmp = _head;
            for (size_t i = 0; i < idx; ++i)
                tmp = tmp->next;
            return tmp->value;
        }
        throw std::out_of_range("");
    }

    Node* append(const Item& value) {
        if (_size) {
            Node* tmp = _head;
            while (tmp->next) { tmp = tmp->next; }
            tmp->next = new Node{ value, nullptr, tmp };
            _size++;
            return tmp->next;
        }
        else {
            _head = new Node{ value, nullptr, nullptr };

            _size++;
            return _head;
        }

    }

    Node* min() const {
        if (!_size) return nullptr;
        Node* tmp = _head;
        Node* min = _head;
        while (tmp->next) {
            if (tmp->next->value < min->value)
                min = tmp->next;
            tmp = tmp->next;
        }
        return min;
    }

    Node* max() const {
        if (!_size) return nullptr;
        Node* tmp = _head;
        Node* max = _head;
        while (tmp->next) {
            if (tmp->next->value > max->value)
                max = tmp->next;
            tmp = tmp->next;
        }
        return max;
    }

    void startOddEndEven() {
        if (_size == 0) return;
        Node* start_odd = _head;
        Node* start_even = _head->next;
        Node* tmp_odd = _head;
        Node* tmp_even = _head->next;
        Node* current = tmp_even;
        for (size_t i = 2; i < _size && current->next; i += 2) {
            Node* next_odd = current->next;
            Node* next_even = current->next->next;
            tmp_odd->next = next_odd;
            next_odd->prev = tmp_odd;
            tmp_even->next = next_even;
            if (next_even)
                next_even->prev = tmp_even;
            tmp_odd = next_odd;
            tmp_even = next_even;
            current = tmp_even;
        }
        tmp_odd->next = start_even;
        if (start_even) start_even->prev = tmp_odd;
    }

    void toHead(Node* value) {
        Node* current = value;
        while (current->prev) {
            Node* next = current->next;
            Node* prev = current->prev;
            current->prev->next = current;
            prev->next = next;
            current->prev = prev->prev;
            current->next = prev;
            next->prev = prev;
            prev->prev = current;

        }
        _head = current;
    }

    Node* find(const Item& value) {
        Node* current = _head;
        while (current && current->next) {
            if (current->value == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void swapNext(Node* lhs,
                  Node* rhs) {
        if (!lhs || !rhs) return;
        lhs = lhs->next;
        rhs = rhs->next;
        if (!lhs || !rhs) return;
        Node* lhs_next = lhs->next;
        Node* lhs_prev = lhs->prev;
        Node* rhs_next = rhs->next;
        Node* rhs_prev = rhs->prev;
        if (lhs_prev) lhs_prev->next = rhs;
        if (lhs_next) lhs_next->prev = rhs;
        if (rhs_prev) rhs_prev->next = lhs;
        if (rhs_next) rhs_next->prev = lhs;
        lhs->next = rhs_next;
        lhs->prev = rhs_prev;
        rhs->next = lhs_next;
        rhs->prev = lhs_prev;
    }

    void toTail(Node* value) {
        Node* current = value;
        while (current->next) {
            Node* next = current->next;
            Node* prev = current->prev;
            current->next->prev = current;
            current->next = next->next;
            next->prev = prev;
            current->prev = next;
            next->next = current;
            prev->next = next;
        }
    }

    void remove(Node* target) {
        if (!target) return;
        Node* current = _head;
        while (current->next && current != target) current = current->next;
        if (current == target) {
            Node* next = current->next;
            Node* prev = current->prev;
            if (next)
                next->prev = prev;
            if (prev)
                prev->next = next;
            if (current == _head)
                _head = next;
            delete current;
            _size--;
        }
    }

    template<typename Func>
    void filter(Func pred) {
        Node* current = _head;
        while (current) {
            if (pred(current->value)) {
                Node* tmp = current;
                current = current->next;
                remove(tmp);
            }
            else current = current->next;
        }
    }

    ~List() {
        while (_head->next) {
            Node* tmp = _head;
            _head = tmp->next;
            delete tmp;
        }
        delete _head;
        _size = 0;
    }

private:
    Node* _head = nullptr;
    size_t _size = 0;
};

int main() {
    List l{ 1, 2, 433, 5,11, 5 ,4 };
    l.toHead(l.max());
    l.toTail(l.min());
    l.startOddEndEven();
    l.filter([](const auto& value) {return !(value % 2); });
    for (size_t i = 0; i < l.size(); ++i)
        std::cout << l[i] << std::endl;
    std::cout << std::endl;
    l.swapNext(l.find(5), l.find(1));
    for (size_t i = 0; i < l.size(); ++i)
        std::cout << l[i] << std::endl;

}