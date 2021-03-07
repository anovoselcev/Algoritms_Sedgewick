

#include <iostream>
#include <vector>
void deleteMultySpaces(std::string& str) {
    std::vector<std::pair<size_t, size_t>> to_delete;
    bool space = false;
    size_t len = 0;
    int pos = -1;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ' ' && !space) {
            pos = i; len = 1;
            space = true;
        }
        else if (str[i] == ' ' && space) len++;
        else if (str[i] != ' ') {
            space = 0;
            if(len > 1)
                to_delete.push_back({ pos, len - 1 });
            pos = -1;
            len = 0;

        }
    }
    size_t offset = 0;
    for (const auto& el : to_delete) {
        str.erase(el.first - offset, el.second);
        offset += el.second;
    }

}

int main()
{
    std::string str = "fsdfgfrs     adadad      a a";
    deleteMultySpaces(str);
    std::cout << str << std::endl;
}
