#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Main {
    std::vector<long long> constraints;
    long long N;
    long long result;

public:
    Main() {
        std::cin >> N;
        for (int i = 0; i < 5; ++i) {
            long long constraint;
            std::cin >> constraint;
            this->constraints.push_back(constraint);
        }

        calc();
    }

    void calc() {
        long long min = std::numeric_limits<long long>::max();
        for (long long c : this->constraints) {
            min = std::min(min, c);
        }
        long long time = this->N / min;
        if (this->N % min != 0) {
            ++time;
        }
        time += 4;
        this->result = time;
    }

    long long get_result() {
        return this->result;
    }
};

int main() {
    Main instance;
    std::cout << instance.get_result() << std::endl;

    return 0;
}

// 
