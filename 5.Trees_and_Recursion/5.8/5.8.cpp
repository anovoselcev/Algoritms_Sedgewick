#include <string>
#include <iostream>

int calc(const std::string& expr, size_t& i) {
	int result = 0;
	while (expr[i] == ' ') ++i;
	if (expr[i] == '+') {
		i++;
		return calc(expr, i) + calc(expr, i);
	}
	if (expr[i] == '-') {
		i++;
		return calc(expr, i) - calc(expr, i);
	}
	if (expr[i] == '*') {
		i++;
		return calc(expr, i) * calc(expr, i);
	}
	if (expr[i] == '/') {
		i++;
		return calc(expr, i) / calc(expr, i);
	}

	while (expr[i] >= '0' && expr[i] <= '9')
		result = result * 10 + (expr[i++] - '0');

	return result;
}

int main() {
	std::string expression;
	size_t i = 0;
	std::getline(std::cin, expression);
	std::cout << calc(expression, i) << std::endl;
}