#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    int count = 0;

    while (true) {
        std::vector<int> evenNumbers;
        for (int i : numbers) {
            if (i % 2 == 0) {
                evenNumbers.push_back(i / 2);
            }
        }

        if (evenNumbers.size() == N) {
            count++;
            numbers = evenNumbers;
        } else {
            break;
        }
    }

    std::cout << count << std::endl;

    return 0;
}  // 
