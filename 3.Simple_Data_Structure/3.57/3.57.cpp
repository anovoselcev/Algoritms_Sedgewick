#include <iostream>

namespace {
    size_t strlen(const char* str) {
        size_t result = 0;
        for (const char* ch = str; *ch != '\0'; ch++)
            result++;
        return result;
    }

    const char* strcat(const char* lhs,
        const char* rhs) {
        size_t len_lhs = strlen(lhs);
        size_t len_rhs = strlen(rhs);
        char* result = new char[len_lhs + len_rhs + 1];
        result[len_lhs + len_rhs] = '\0';
        for (size_t i = 0; i < len_lhs; ++i) result[i] = lhs[i];
        for (size_t i = 0; i < len_rhs; ++i) result[i + len_lhs] = rhs[i];
        return result;
    }

    void Test() {
        std::cout << strcat("Hello ", "World!") << std::endl;
    }
}
int main()
{
    Test();
}
