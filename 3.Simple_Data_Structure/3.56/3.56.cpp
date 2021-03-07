#include <iostream>

bool isPalindrom(const char* str, size_t len = 0) {
	if (!len)
		for (const char* ch = str; *ch != '\0'; ++ch) len++;
	for (size_t i = 0; i < len / 2; ++i)
		if (str[i] != str[len - 1 - i]) return false;
	return true;
}

int main() {
	std::cout << isPalindrom("uyu") << std::endl;
	std::cout << isPalindrom("uyu", 3) << std::endl;
	std::cout << isPalindrom("rtre", 4) << std::endl;
	std::cout << isPalindrom("rtre") << std::endl;
	return 0;
}