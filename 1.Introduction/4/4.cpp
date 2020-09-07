// Взвешенная версия быстрого объединения
#include <iostream>
#include <array>
#include <numeric>

constexpr int N = 10000;

int main() {
	int i, j, p, q;
	std::array<int, N> id;
	std::array<int, N> sz;
	sz.fill(1);
	std::iota(id.begin(), id.end(), 0);
	while (std::cin >> p >> q) {
		for (i = p; i != id[i]; i = id[i])
			id[i] = id[id[i]];
		for (j = q; j != id[j]; j = id[j])
			id[j] = id[id[j]];
		if (i == j) continue;
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		std::cout << " " << p << " " << q << std::endl;
	}
	return 0;
}