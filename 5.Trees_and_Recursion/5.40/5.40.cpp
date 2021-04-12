
#include <iostream>

size_t Func(size_t N) {
    static size_t* know = [] {
        size_t* ptr = new size_t[10000];
        std::memset(ptr, 0, 10000);
        return ptr;
    }();
    if (N == 0) return know[0] = 0;
    if (know[N]) return know[N];
    return know[N] = N / 2 + Func(std::floor(N / 2)) + Func(std::ceil(N / 2));
    
}

int main(){
    size_t N;
    std::cin >> N;
    std::cout << Func(N) << std::endl;;
}
