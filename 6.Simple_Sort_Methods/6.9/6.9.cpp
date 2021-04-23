
#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ranges>

void CheckAveragePerfomanceOfSort() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dn(0, 1000);
    size_t size = 10;
    for (size_t i = 0; i < 10; ++i, size *= 5) {
        std::vector<double> sample(size);
        for (size_t j = 0; j < size; ++j) sample[j] = dn(gen);

        auto start = std::chrono::steady_clock::now();
        std::ranges::sort(sample);
        auto end = std::chrono::steady_clock::now();
        std::cout << "#Sample_" << i << " with size = "
            << size << ", total time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << " us" << std::endl;
    }
}

int main(){
    CheckAveragePerfomanceOfSort();
}

