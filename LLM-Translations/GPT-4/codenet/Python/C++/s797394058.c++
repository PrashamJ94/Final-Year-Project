#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int x = 1;

    std::vector<int> N_list(N);
    for (int i = 0; i < N; i++) {
        N_list[i] = x + 1;
        x++;
    }

    std::vector<std::vector<int>> n;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                std::vector<int> temp = {N_list[i], N_list[j], N_list[k]};
                n.push_back(temp);
            }
        }
    }

    int m = n.size();
    std::cout << m << std::endl;

    return 0;
} // 
