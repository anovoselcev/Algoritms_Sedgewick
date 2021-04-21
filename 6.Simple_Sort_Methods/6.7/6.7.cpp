#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

template<typename F>
bool CheckStable(F f, size_t N = 100000) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> du{ -100, 100};
    std::uniform_int_distribution<int> dn{ -5, 10 };
    std::vector<std::pair<int, int>> samples(N);

    for (size_t i = 0; i < N; ++i) samples[i] = { du(gen), dn(gen) };

    auto firstSort = samples;
    f(firstSort.begin(), firstSort.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
        });

    f(firstSort.begin(), firstSort.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
        });
    
    auto secondSort = std::move(samples);
    std::shuffle(secondSort.begin(), secondSort.end(), gen);

    f(secondSort.begin(), secondSort.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
    });

    f(secondSort.begin(), secondSort.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
        });

    for (size_t i = 0; i < N; ++i) {
        if (firstSort[i].first != secondSort[i].first)
            return false;
    }
    return true;
}

int main(){
    std::cout << CheckStable([](auto it_beg, auto it_end, auto cmp) {std::sort(it_beg, it_end, cmp); }) << std::endl;
    std::cout << CheckStable([](auto it_beg, auto it_end, auto cmp) {std::stable_sort(it_beg, it_end, cmp); }) << std::endl;
}