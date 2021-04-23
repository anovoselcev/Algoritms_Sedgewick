#include <iostream>
#include <random>
#include <algorithm>

template <typename T, template<typename, typename> class C, typename Allocator = std::allocator<T>>
void shakerSort(C<T, Allocator>& arr) {
	size_t control = arr.size();
	size_t left = 0;
	size_t right = arr.size() - 1;
	do {
		for (size_t i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				control = i;
			}
		}
		right = control;
		for (size_t i = right; i > left; i--) {
			if (arr[i] < arr[i - 1]) {
				std::swap(arr[i], arr[i - 1]);
				control = i;
			}
		}
		left = control;
	} while (left < right);
}

int main(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> dn(0, 1000);
	std::vector<double> sample(10000);
	for (size_t i = 0; i < 10000; ++i) sample[i] = dn(gen);
	auto qsample = sample;
	shakerSort(sample);
	std::sort(qsample.begin(), qsample.end());
	for (size_t i = 0; i < 10000; ++i) {
		if (sample[i] != qsample[i]) throw std::runtime_error("shake sort wrong");
	}

}
