
#include <iostream>
#include <array>

std::array<uint16_t, 1000> counter;

int main(){
    counter.fill(0);
    uint16_t value;
    while (std::cin >> value) {
        if(value <= 1000)
            counter[value - 1]++;
    }
}

