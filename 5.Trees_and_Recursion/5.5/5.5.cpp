
#include <iostream>



int main(){
    int a, b;
    std::cin >> a >> b;
    while (a && b) {
        if (abs(a) > abs(b)) a = a % b;
        else b = b % a;
    }
    std::cout << std::max(a, b) << std::endl;
}

