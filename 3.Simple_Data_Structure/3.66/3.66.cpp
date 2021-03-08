
#include <iostream>
#include <array>
#include <vector>
#include <list>

template <typename T>
class SpareMatrix {
public:
    SpareMatrix() = default;
    SpareMatrix(const std::vector<std::vector<T>>& data) {
        _data.resize(data.size());
        _n = data.size();
        if (_n) _m = data[0].size();
        for (size_t i = 0; i < data.size(); ++i){
            for (size_t j = 0; j < data[i].size(); ++j) {
                if (data[i][j] != T{})
                    std::next(std::begin(_data), i)->push_back(data[i][j]);
            }
        }
    }

    SpareMatrix(const std::initializer_list<std::initializer_list<T>>& data) {
        _data.resize(data.size());
        _n = data.size();
        for (size_t m = 0, i = 0; const auto & row : data) {
            for (const auto& el : row) {
                m++;
                if (el != T{})
                    std::next(std::begin(_data), i)->push_back(el);
            }
            if (m > _m) _m = m;
            m = 0;
            i++;
        }
    }
    template<size_t N, size_t M>
    SpareMatrix(const std::array<std::array<T, M>, N>& data) {
        _data.resize(N);
        _n = N; _m = M;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                if (data[i][j] != T{})
                    std::next(std::begin(_data), i)->push_back(data[i][j]);
            }
        }
    }
    template<size_t N, size_t M>
    SpareMatrix(const T(&data)[N][M]) {
        _data.resize(N);
        _n = N; _m = M;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                if (data[i][j] != T{})
                    std::next(std::begin(_data), i)->push_back(data[i][j]);
            }
        }
    }


private:
    size_t _n = 0;
    size_t _m = 0;
    std::list<std::list<T>> _data;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const SpareMatrix<U>&);

};
template<typename U>
std::ostream& operator<<(std::ostream& out, const SpareMatrix<U>& matr){
    for (const auto& row : matr._data) {
        for (const auto& el : row)
            out << el << " ";
        out << '\n';
    }
    return out;
}
int main()
{
    SpareMatrix data({ {1, 2, 0,  3}, {3, 5, 8, 0} });
    std::cout << data << std::endl;
}