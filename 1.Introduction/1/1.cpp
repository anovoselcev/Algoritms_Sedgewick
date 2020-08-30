// Решение задачи связности методом быстрого поиска
#include <iostream>
#include <array>
#include <numeric>

constexpr int N = 10000;

int main(){
    int p, q;
    std::array<int, N> id;
    std::iota(id.begin(), id.end(), 0);
    while (std::cin >> p >> q) {
        int t = id[p];
        if (t == id[q])
            continue;
        for (int i = 0; i < N; ++i)
            if (id[i] == t) id[i] = id[q];
        std::cout << " " << p << " " << q << std::endl;
    }
    return 0;
}
