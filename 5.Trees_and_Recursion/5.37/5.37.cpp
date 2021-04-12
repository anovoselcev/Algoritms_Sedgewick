#include <iostream>


size_t Fib(size_t N) {
    static size_t known[1000];
    if (known[N]) return known[N];
    size_t t = 1;
    if (!N) return 0;
    if (N > 1) t = Fib(N - 1) + Fib(N - 2);
    return known[N] = t;
}

int Mod(size_t N, int M) {
    return Fib(N) % M;
}

int main(){
    size_t N;
    int M;
    std::cin >> N >> M;
    std::cout << Fib(N) << std::endl;
    std::cout << Mod(N, M) << std::endl;
}
