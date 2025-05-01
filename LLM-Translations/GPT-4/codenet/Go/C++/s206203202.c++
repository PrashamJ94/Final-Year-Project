#include <iostream>
#include <algorithm>
#include <cmath>

int Abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

int main(){
    int N, K;
    std::cin >> N >> K;

    int x;
    x = N % K;
    x = min(std::abs(x - K), x);
    std::cout << x << std::endl;
    return 0;
}
// 
