#include <iostream>
#include <cmath>

template<typename T>
T max(T* data, size_t l, size_t r) {
    if (l == r) return data[l];
    size_t bin_part =  r - l > 1 ? std::pow(2, static_cast<int>(std::log(r - l))) : 0;
    T max_l = max(data, l, bin_part + l);
    T max_r = max(data, bin_part + l + 1, r);
    if (max_l > max_r) return max_l;
    else return max_r;
}

int main(){
    int data[7] = { 1 ,4, 65, 11, 434, 44, 100 };
    std::cout << max(&data[0], 0, 7) << std::endl;
}
