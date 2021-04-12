
#include <iostream>


double CN(size_t N) {
    static double* know = [] {
        double* ptr = new double[10000];
        std::memset(ptr, 0, 10000);
        return ptr;
    }();

    if (N == 0) return know[0] = 1;
    if (know[N]) return know[N];
    
    for (size_t i = 1; i < N; ++i) know[N] += CN(i - 1) + CN(N - i);
    return know[N] = N + know[N] / static_cast<double>(N);
}

int main(){
    size_t N;
    std::cin >> N;
    std::cout << CN(N) << std::endl;
}
