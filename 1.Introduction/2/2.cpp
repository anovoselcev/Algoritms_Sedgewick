// Решение задачи связности методом быстрого объединения
#include <iostream>
#include <array>
#include <numeric>

constexpr int N = 10000;

int main() {
    int p, q;
    std::array<int, N> id;
    std::iota(id.begin(), id.end(), 0);
    while (std::cin >> p >> q) {
        int i, j;
        for (i = 0; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j)
            continue;
        id[i] = j;
        std::cout << " " << p << " " << q << std::endl;
    }
    return 0;
}