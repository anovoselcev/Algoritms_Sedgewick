// 3.61.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

size_t theMostLongestSpaceSeq(const std::string& str) {
    size_t result = 0;
    size_t new_result = 0;
    size_t current = 1;
    bool oneSeq = false;
    size_t n = 10;
    for (size_t i = 0; i < str.size(); i += current) {
        if (str[i] == 32) {
            if (!oneSeq) {
                oneSeq = true;
                if (result > n && i + result < str.size()) {
                    if (str[i + result] == 32)
                        new_result = result - 1;

                    else {
                        oneSeq = false;
                        new_result = 0;
                    }
                    current += result;
                }
                else if (i + result >= str.size()) break;
            }
            else current = 1;
            new_result++;
        }
        else {
            oneSeq = false;
            current = 1;
            if (new_result > result) result = new_result;
            new_result = 0;
        }
    }
    if (new_result > result) result = new_result;
    return result;
}

int main() {
    std::string test("da   d a  d          ddd              da \
        aadsadw                                                 \
        asdad                                                    \
                                                                  \
dd  ");
    std::cout << theMostLongestSpaceSeq(test)  << std::endl;
}