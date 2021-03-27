
#include <iostream>

size_t Fact(size_t N) {
    if (N == 0) return 1;
    return N * Fact(N - 1);
}

size_t FindMod(size_t N, size_t M) {
    if (N >= M) return 0;
    return Fact(N);
}

int main(){
    size_t N, M;
    std::cin >> N >> M;
    std::cout << FindMod(N, M);
}
