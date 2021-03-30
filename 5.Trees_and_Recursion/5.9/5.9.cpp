#include <string>
#include <iostream>
#include <stack>

std::stack<int> _stack;

auto top_pop = [] {
	auto tmp = _stack.top();
	_stack.pop();
	return tmp;
};

int calc(const std::string& expr, size_t& i) {
	int result = 0;
	while (expr[i] == ' ') ++i;
	if (expr[i] == '+') {
		i++;
		result = top_pop() + top_pop();
	}
	else if (expr[i] == '-') {
		i++;
		result = top_pop() - top_pop();
	}
	else if (expr[i] == '*') {
		i++;
		result = top_pop() * top_pop();
	}
	else if (expr[i] == '/') {
		i++;
		result = top_pop() / top_pop();
	}
	else if (expr[i] >= '0' && expr[i] <= '9') {
		while (expr[i] >= '0' && expr[i] <= '9')
			result = result * 10 + (expr[i++] - '0');
	}

	_stack.push(result);

	if (i < expr.size()) return calc(expr, i);
	return result;
}

int main() {
	std::string expression;
	size_t i = 0;
	std::getline(std::cin, expression);
	std::cout << calc(expression, i) << std::endl;
}