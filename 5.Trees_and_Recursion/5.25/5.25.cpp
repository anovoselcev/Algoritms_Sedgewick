
#include <iostream>
#include <sstream>

void rank(size_t N, bool** numbers, size_t idx) {
    if (idx < N) {
        size_t i = std::pow(2, N - 1) - 1;
        std::memcpy(&numbers[idx][0], &numbers[idx - 1][0], std::pow(2, N - 1));
        while (numbers[idx][i]) { i--; }
        numbers[idx][i++] = true;
        for (; i < std::pow(2, N - 1); i++) numbers[idx][i] = false;

        rank(N, numbers, idx + 1);
    }
}


int main(){
    size_t N;
    std::cin >> N;
    bool** numbers = new bool* [N];
    for (size_t i = 0; i < N; ++i) numbers[i] = new bool[std::pow(2, N - 1)](false);
    rank(N, numbers, 1);
    std::cout << 0 << std::endl;
    for (size_t i = 1; i < N; ++i) {
        std::stringstream ss;
        bool start = false;
        for (size_t j = 0; j < std::pow(2, N - 1); j++) {
            if (numbers[i][j] == true && !start) start = true;
            if(start) ss << numbers[i][j];
        }
        std::cout << ss.str() << std::endl;
    }
    return 0;
}

