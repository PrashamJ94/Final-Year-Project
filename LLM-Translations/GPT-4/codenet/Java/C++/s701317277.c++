#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main(){
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    int min = INT_MAX;
    int count = 0;
    long sum = 0;
    for(int i = 0; i < N; i++){
        std::cin >> A[i];
        if(A[i] < 0)
            count++;
        min = std::min(min, std::abs(A[i]));
        sum += std::abs(A[i]);
    }

    if(count % 2 == 0)
        std::cout << sum << std::endl;
    else {
        std::cout << sum - min * 2 << std::endl;
    }

    return 0;
}
//
