#include <iostream>
#include <vector>

struct State {
    size_t count,
           src,
           tmp,
           dst;
    int step;
};

void tower(size_t count, size_t src, size_t dst, size_t tmp) {
    std::vector<State> stack;
    stack.push_back({ count, src, tmp, dst, 0 });
    while (!stack.empty()) {
        auto& state = stack.back();
        if (state.step == 0) {
            if (!state.count) stack.pop_back();
            else {
                state.step++;
                stack.push_back({ state.count - 1, state.src, state.dst, state.tmp,0 });
            }
        }
        else if (state.step == 1) {
            state.step++;
            stack.push_back({ state.count - 1, state.tmp, state.dst, state.src, 0 });
        }
        else stack.pop_back();

    }
}


int main(){
    size_t N, src, dst, tmp;
    std::cin >> N >> src >> dst >> tmp;
    tower(N, src, dst, tmp);
    
    return 0;
}

