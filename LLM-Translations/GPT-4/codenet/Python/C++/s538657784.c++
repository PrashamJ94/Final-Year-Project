#include<iostream>
#include<cmath>

int main() {
    int N;
    std::cin >> N;
    int sqN = static_cast<int>(std::sqrt(N));
    for(int i = 0; i < sqN; i++) {
        if(N % (sqN-i) == 0) {
            std::cout << static_cast<int>(N / (sqN-i) + sqN-i) - 2 << std::endl;
            break;
        }
    }
    return 0;
}
// 
