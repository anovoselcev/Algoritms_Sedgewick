#include <iostream>
#include <array>
#include <random>

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> d{ 1, 1000 };
    uint16_t result = 0;
    uint16_t cache = d(gen);
    for (size_t i = 0; i < 100000; ++i) {
        uint16_t value = d(gen);
        if (value != cache)
            result++;
        else {
            result = 0;
            cache = value;
        }
    }
    std::cout << result << std::endl;
}
