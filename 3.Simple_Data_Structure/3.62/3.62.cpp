#include <iostream>

template<typename T>
T*** malloc3d(size_t N, size_t M, size_t K, T def = T{}) {
    T*** data = new T * *[N];
    for (size_t i = 0; i < N; ++i) {
        data[i] = new T * [M];
        for (size_t j = 0; j < M; ++j) {
            data[i][j] = new T[K]({});
            if (def != T{}) {
                for (size_t k = 0; k < K; ++k)
                    data[i][j][k] = def;
            }
        }
    }
    return data;
}

int main(){
    auto matrix = malloc3d<size_t>(10, 20, 30, 123);
    for (size_t i = 0; i < 20; ++i) {
        for (size_t j = 0; j < 30; ++j) {
            auto el = matrix[0][i][j];
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}
