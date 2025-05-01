
#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    std::string currency;
    double value;
    for(int i = 0; i < N; i++) {
        std::cin >> value >> currency;
        if(currency == "JPY") {
            x[i] = value * 1.0;
        } else if(currency == "BTC") {
            x[i] = value * 380000.0;
        }
    }
    double sum = 0.0;
    for(int i = 0; i < N; i++) {
        sum += x[i];
    }
    std::cout << sum;
    return 0;
} // End of Code


