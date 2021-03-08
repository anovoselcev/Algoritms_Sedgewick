
#include <iostream>

int compare(const void* lhs,
            const void* rhs) {
    return strcmp(*(char**)(lhs), *(char**)(rhs));
}



int main(){

    const size_t N = 10000;
    const size_t buf = 100;
    char* data[N];
    for (size_t i = 0; i < N; ++i) {
        char* tmp = new char[100];
        if (!std::cin >> *tmp) break;
        data[i] = tmp;
    }
    qsort(data, N, sizeof(char*), compare);
    std::cout << "Hello World!\n";
}
