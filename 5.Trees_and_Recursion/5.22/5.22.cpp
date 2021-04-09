#include <iostream>

void rule(size_t lhs,
		  size_t rhs,
		  size_t h,
		  size_t& len,
		  size_t& idx,
		  size_t target_idx) {

	size_t mid = (lhs + rhs) / 2;
	if (h) {
		rule(lhs, mid, h - 1, len, idx, target_idx);
		if (idx++ == target_idx) len = mid;
		rule(mid, rhs, h - 1, len, idx, target_idx);
	}
}

int main(){
	size_t i, n, h, len, idx = 0;
	std::cin >> n >> i >> h;
	rule(0, std::pow(2, n) - 1, h, len, idx, i);
	std::cout << len << std::endl;

	return 0;
}

