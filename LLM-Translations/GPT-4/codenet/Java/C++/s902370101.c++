
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    int max = 0;
    int min = 10000;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        if (max < array[i]) {
            max = array[i];
        }

        if (min > array[i]) {
            min = array[i];
        }
    }
    std::cout << max - min << std::endl;
    return 0;
}

// 
