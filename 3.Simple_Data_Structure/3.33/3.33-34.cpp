// 3.33.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

    Node* min() const{
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

int main(){
    List l{ 1, 2, 433, 5,11, 5 };
    std::cout << l.max()->value << std::endl;
    l.toHead(l.max());
    std::cout << l[0] << std::endl;
    l.toTail(l.min());
    std::cout << l[5] << std::endl;
    for (size_t i = 0; i < l.size(); ++i)
        std::cout << l[i] << std::endl;

}
