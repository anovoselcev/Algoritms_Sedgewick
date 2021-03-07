
#include <iostream>
#include <map>
#include <vector>
#include <ranges>
#include <algorithm>

void FreqTable(const char* str) {
    std::map<char, size_t> freq;
    for (const char* ch = str; *ch != '\0'; ch++)
        freq[*ch]++;
    std::vector<std::pair<size_t, char>> tmp;
    tmp.reserve(freq.size());
    for (const auto& el : freq)
        tmp.push_back({ el.second, el.first });
    std::ranges::sort(tmp);
    for(const auto& el : tmp | std::views::reverse)
        std::cout << el.second << ": " << el.first << std::endl;
}

int main(){
    FreqTable("sgredgaefcac weFWEGRGFAWEFAWGDCVDFG QWDQ QWEDADefsfdf");
}