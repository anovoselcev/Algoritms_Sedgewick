
#include <iostream>
#include <cmath>

double LogOFfactorial(size_t N) {
    if (N == 0) return 0;
    return std::log10(N) + LogOFfactorial(N - 1);
}

int main(){
    size_t N = 0;
    std::cin >> N;
    std::cout << LogOFfactorial(N);
}