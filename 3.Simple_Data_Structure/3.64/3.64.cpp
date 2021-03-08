
#include <iostream>
size_t gcd(size_t a, size_t b) {
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

int main(){
    const size_t N = 1000, M = 1000;
    size_t data[N][M];
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            size_t value = gcd(i, j);
            if (value == 1)
                data[i][j] = 1;
            else
                data[i][j] = 0;
        }
    }
    std::cout << "Hello World!\n";
}
