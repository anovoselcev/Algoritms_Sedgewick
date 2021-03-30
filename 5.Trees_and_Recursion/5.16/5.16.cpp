
#include <iostream>

int max(int* data, size_t idx, size_t size) {
    int m = data[idx];
    if (idx == size - 1) return m;
    int n_max = max(data, ++idx, size);
    if (m > n_max) return m;
    else return n_max;
}

int main(){
    int data[12] = { 0 ,12, 24, 31, -121, 23, 32, 121, 65, 56, 123, 67 };
    std::cout << std::max(data[0], max(&data[0], 1, 12));
}
