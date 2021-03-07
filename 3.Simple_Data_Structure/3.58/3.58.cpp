
#include <iostream>

bool contains(const std::string& sub,
              const std::string& target) {
    if (target.empty()) return true;
    if (sub.size() > target.size()) return false;
    size_t k = 0;
    for (const auto& el : target) {
        if (el == sub[k]) {
            k++;
            if (k == sub.size()) return true;
        }
        else if (k > 0 && sub[0] == el) k = 1;
        else k = 0;
    }
    return false;
}

int main(){
    std::string input, sub;
    std::cin >> sub;
    while (std::cin >> input)
        std::cout << contains(sub, input) << std::endl;
}
