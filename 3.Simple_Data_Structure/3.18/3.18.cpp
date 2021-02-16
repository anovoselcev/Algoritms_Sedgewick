
#include <iostream>
#include <random>
#include <array>

std::array<bool, 1000> counter;

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> d{ 1, 1000 };
    uint16_t result = 0;
    uint16_t cache = d(gen);
    counter.fill(false);
    counter[cache - 1] = true;
    result++;
    for (size_t i = 0; i < 100000; ++i) {
        uint16_t value = d(gen);
        if (!counter[value - 1]) {
            result++;
            counter[value - 1] = true;
        }
        else if (result == 1000) {
            result = 0;
            counter.fill(false);
        }
        else
            result++;
    }
    std::cout << result << std::endl;
}
