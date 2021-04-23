#include <iostream>
#include <concepts>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include <sstream>

template<typename T>
concept Number = requires{std::is_floating_point<T>::value || std::is_integral<T>::value; };

template <Number T>
class Complex {
	T _re = 0,
		_im = 0;

	T sqrModule() const { return _re * _re + _im * _im; }

public:
	Complex() = default;

	explicit Complex(T re, T im) : _re(re), _im(im) {}

	Complex(const Complex& other) : Complex(other._re, other._im) {}

	Complex(Complex&& other) noexcept : Complex(other._re, other._im)  {}

	Complex& operator=(const Complex& other) {
		_re = other._re;
		_im = other._im;
		return *this;
	}

	Complex& operator=(Complex&& other) noexcept {
		_re = other._re;
		_im = other._im;
		return *this;
	}

	~Complex() = default;

	T module() const noexcept { return sqrt(sqrModule()); }

	template<Number U>
	bool operator==(const Complex<U>& other) const noexcept {
		return _re == other._re && _im == other._im;
	}

	template<Number U>
	bool operator<(const Complex<U>& other) const noexcept {
		return sqrModule() < other.sqrModule();
	}

	template<Number U>
	Complex operator+(const Complex<U>& other) const noexcept {
		T tmp_re = _re + other._re;
		T tmp_im = _im + other._im;
		return Complex(tmp_re, tmp_im);
	}

	template<Number U>
	Complex operator-(const Complex<U>& other) const noexcept {
		T tmp_re = _re - other._re;
		T tmp_im = _im - other._im;
		return Complex(tmp_re, tmp_im);
	}

	template<Number U>
	Complex& operator+=(const Complex<U>& other) const noexcept {
		_re += other._re;
		_im += other._im;
		return *this;
	}
	template<Number U>
	friend std::ostream& operator<<(std::ostream& os, const Complex<U>& num);
};
template<Number T>
 std::ostream& operator<<(std::ostream& os, const Complex<T>& num) {
	 std::ostringstream ss;
	 ss << "{" << num._re << ": " << num._im << "}";
	 os << ss.str();
	 return os;
}

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> dn(0, 1000);
	std::vector<Complex<double>> sample(1000);
	for (size_t i = 0; i < 1000; ++i) sample[i] = Complex(dn(gen), dn(gen));
	std::sort(sample.begin(), sample.end());
	std::cout << sample[0] << std::endl;
	std::cout << std::is_sorted(sample.begin(), sample.end()) << std::endl;
}